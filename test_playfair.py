import unittest
from playfair import encrypt, decrypt

class TestCalculations(unittest.TestCase):

    def test1(self):
        plainText = "Hello World"
        #cypherTable = "playfirbcdeghkmnoqstuvwxz"
        password = "playfir"
        correctAnswer = "kgyvrvvqgrbf"
        answer = encrypt(plainText, password)
        self.assertEqual(answer, correctAnswer, 'Test '+plainText+' failed.')

        plainTextDecrypted = "helloworlda"
        answer2 = decrypt(answer, password)
        self.assertEqual(answer2, plainTextDecrypted, 'Test '+plainText+' failed.')

    def test2(self):
        plainText = "fuckmeintheass"
        #cypherTable = "sqxpforclabeuzhgmivtykwnd"
        password = "sqxpforclabeuzhgmivtykwnd"
        correctAnswer = "xhrwkmvwdthrqpfo"
        answer = encrypt(plainText, password)
        self.assertEqual(answer, correctAnswer, 'Test '+plainText+' failed.')

        plainTextDecrypted = "fuckmeintheassa"
        answer2 = decrypt(answer, password)
        self.assertEqual(answer2, plainTextDecrypted, 'Test '+plainText+' failed.')

    def test3(self):
        plainText = "communicate"
        #cypherTable = "computerabdfghiklnqsvwxyz"
        password = "computer"
        correctAnswer = "omrmpcsgpter"
        answer = encrypt(plainText, password)
        self.assertEqual(answer, correctAnswer, 'Test '+plainText+' failed.')

        plainTextDecrypted = "communicate"
        answer2 = decrypt(answer, password)
        self.assertEqual(answer2, plainTextDecrypted, 'Test '+plainText+' failed.')

    def test4(self):
        plainText = "instrumentsz"
        #cypherTable = "monarchybdefgiklpqstuvwxz"

        password = "monarchy"
        correctAnswer = "gatlmzclrqtx"
        answer = encrypt(plainText, password)
        self.assertEqual(answer, correctAnswer, 'Test '+plainText+' failed.')

        plainTextDecrypted = "instrumentsz"
        answer2 = decrypt(answer, password)
        self.assertEqual(answer2, plainTextDecrypted, 'Test '+plainText+' failed.')

if __name__ == '__main__':
    unittest.main()
