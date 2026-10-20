"""Read-only flow regressions; no EDA tools or PDK required."""
import hashlib
import importlib.util
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
spec = importlib.util.spec_from_file_location('collect_results', ROOT / 'tools/gds/collect_results.py')
collect = importlib.util.module_from_spec(spec)
spec.loader.exec_module(collect)


interface_spec = importlib.util.spec_from_file_location(
    'macro_interfaces', ROOT / 'scripts/gds/check_macro_interfaces.py')
interfaces = importlib.util.module_from_spec(interface_spec)
interface_spec.loader.exec_module(interfaces)


class EvidenceTests(unittest.TestCase):
    def test_macro_bus_pins_and_unused_output(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            macro = root / 'example'
            macro.mkdir()
            lef = macro / 'example.lef'
            lef.write_text(' PIN data[0]\n PIN data[1]\n PIN done\n PIN VPWR\n')
            path = root / 'top.json'
            path.write_text(json.dumps({'modules': {
                'top': {'cells': {'u': {'type': 'ember_example',
                         'connections': {'data': [2, 3], 'done': []}}}},
                'ember_example': {'ports': {
                    'data': {'bits': [2, 3], 'direction': 'input'},
                    'done': {'bits': [4], 'direction': 'output'}}}}}))
            interfaces.check(path, 'top', ['example'], root)
            lef.write_text(' PIN data[0]\n PIN done\n')
            with self.assertRaisesRegex(ValueError, 'missing LEF pins'):
                interfaces.check(path, 'top', ['example'], root)

    def test_content_bound_audit_required_for_clean_claim(self):
        with tempfile.TemporaryDirectory() as temp:
            directory = Path(temp) / 'xbar'
            directory.mkdir()
            gds = directory / 'xbar.gds'
            gds.write_bytes(b'fixture geometry')
            (directory / 'openroad.log').write_text('Number of violations = 0.\n')
            (directory / 'magic.log').write_text('DRC_COUNT=0\n')
            (directory / 'gds_validation.json').write_text(json.dumps({
                'top': 'ember_xbar', 'recursive_shapes': 1}))
            stat = gds.stat()
            audit = {'top': 'ember_xbar', 'gds_mtime_ns': stat.st_mtime_ns,
                     'gds_bytes': stat.st_size, 'rules_suppressed': False,
                     'whole_layout_flattened_drc': 0,
                     'gds_sha256': hashlib.sha256(gds.read_bytes()).hexdigest()}
            audit_path = directory / 'export_audit.json'
            audit_path.write_text(json.dumps(audit))
            self.assertTrue(collect.parse_block(temp, 'xbar')['flow'].startswith('GDS;'))
            audit['gds_sha256'] = 'wrong'
            audit_path.write_text(json.dumps(audit))
            self.assertFalse(collect.parse_block(temp, 'xbar')['flow'].startswith('GDS;'))
            audit_path.unlink()
            self.assertFalse(collect.parse_block(temp, 'xbar')['flow'].startswith('GDS;'))

    def test_openroad_plain_wns_is_reported(self):
        with tempfile.TemporaryDirectory() as temp:
            directory = Path(temp) / 'fpu4'
            directory.mkdir()
            (directory / 'openroad.log').write_text('wns -48.87\n')
            self.assertEqual(collect.parse_block(temp, 'fpu4')['wns'], -48.87)

    def test_blackboxes_fail_without_explicit_allowance(self):
        with tempfile.TemporaryDirectory() as temp:
            path = Path(temp) / 'synth.json'
            path.write_text(json.dumps({'modules': {
                'top': {'cells': {'u': {'type': 'macro'}}},
                'macro': {'attributes': {'blackbox': '0001'}, 'cells': {}}
            }}))
            command = [sys.executable, str(ROOT / 'scripts/gds/validate_synth.py'),
                       str(path), 'top']
            result = subprocess.run(command, capture_output=True, text=True)
            self.assertEqual(result.returncode, 1)
            self.assertIn('unresolved blackbox', result.stdout)
            result = subprocess.run(command + ['--allow-blackbox', 'macro'],
                                    capture_output=True, text=True)
            self.assertEqual(result.returncode, 0)
            self.assertIn('physical evidence still required', result.stdout)


if __name__ == '__main__':
    unittest.main()
