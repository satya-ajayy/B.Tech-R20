import unittest
from Ex13 import isEvenLst


class MyTestCase(unittest.TestCase):
   
    def test_isEven(self):
        self.assertEqual(isEvenLst([]), True)
        self.assertEqual(isEvenLst([2, 4, 88, 99]), False)
        self.assertEqual(isEvenLst([2, 8, 90, 10]), True)
        self.assertEqual(isEvenLst([44, 66, 88, 22]), True)


if __name__ == '__main__':
    unittest.main()
