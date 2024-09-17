import unittest
from playfair import encrypt

class TestCalculations(unittest.TestCase):

    def test1(self):
        plainText = "helloworld"
        cypherTable = "playfirbcdeghkmnoqstuvwxz"
        correctAnswer = "kgrrqvvgfr"
        answer = encrypt(plainText, cypherTable)
        self.assertEqual(answer, correctAnswer, 'Test 1 failed.')

    def test2(self):
        plainText = "fuckmeintheass"
        cypherTable = "sqxpforclabeuzhgmivtykwnd"
        correctAnswer = "xhrwkmvwdthroo"
        answer = encrypt(plainText, cypherTable)
        self.assertEqual(answer, correctAnswer, 'Test 2 failed.')

    def test3(self):
        plainText = "comxmunicate"
        cypherTable = "computerabdfghiklnqsvwxyz"
        correctAnswer = "omrmpcsgpter"
        answer = encrypt(plainText, cypherTable)
        self.assertEqual(answer, correctAnswer, 'Test 3 failed.')

    def test4(self):
        plainText = "instrumentsz"
        cypherTable = "monarchybdefgiklpqstuvwxz"
        correctAnswer = "gatlmzclrqtx"
        answer = encrypt(plainText, cypherTable)
        self.assertEqual(answer, correctAnswer, 'Test 4 failed.')

if __name__ == '__main__':
    unittest.main()
