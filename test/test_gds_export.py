"""Container integration test; requires pya and the export fixture output.

Run: docker exec ol2 python3 /work/test/test_gds_export.py
"""
from pathlib import Path
import unittest

import pya

ROOT = Path('/work')


class MacroExportTests(unittest.TestCase):
    def test_real_macro_and_mapped_route(self):
        source = pya.Layout()
        source.read(str(ROOT / 'build/gds/xbar/xbar.gds'))
        exported = pya.Layout()
        exported.read(str(ROOT / 'build/gds/export_test.gds'))
        top = exported.cell('ember_export_test')
        self.assertIsNotNone(top)
        instances = list(top.each_inst())
        self.assertEqual(len(instances), 1)
        inst = instances[0]
        self.assertEqual(inst.cell.name, 'ember_xbar')
        self.assertAlmostEqual(inst.trans.disp.x * exported.dbu, 25.0)
        self.assertAlmostEqual(inst.trans.disp.y * exported.dbu, 25.0)
        expected = source.cell('ember_xbar')
        expected_count = sum(expected.shapes(i).size() for i in source.layer_indices())
        actual_count = sum(inst.cell.shapes(i).size() for i in exported.layer_indices())
        self.assertEqual(expected_count, actual_count)
        self.assertGreater(len(list(inst.cell.each_inst())), 0)
        # The fixture's explicit 50um route must be on met3 drawing (70/20),
        # not an arbitrary LEF layer or a full-die abstract obstruction.
        met3 = exported.find_layer(70, 20)
        self.assertIsNotNone(met3)
        boxes = [shape.bbox() for shape in top.shapes(met3).each()]
        self.assertTrue(any(box.width() * exported.dbu >= 50 for box in boxes))
        self.assertFalse(any(box.width() * exported.dbu >= 182.5
                             and box.height() * exported.dbu >= 182.5
                             for box in boxes))


if __name__ == '__main__':
    unittest.main()
