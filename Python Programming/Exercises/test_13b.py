import unittest
from Ex13 import reverseString


class MyTestCase(unittest.TestCase):

    def test_reverseString(self):
        self.assertEqual(reverseString('ajay'), 'yaja')
        self.assertEqual(reverseString('aj'), 'ja')
        self.assertEqual(reverseString(''), '')

    def test_values(self):
        self.assertRaises(TypeError, reverseString, -2)
        self.assertRaises(TypeError, reverseString, -2J)
        self.assertRaises(TypeError, reverseString, 1.345)
        self.assertRaises(TypeError, reverseString, 729)


if __name__ == '__main__':
    unittest.main()
