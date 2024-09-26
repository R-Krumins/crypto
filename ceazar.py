def encrypt(txt, key, reverse=False):
    key = key % 26
    if(reverse): key *= -1
    txt = txt.lower()
    return ''.join([chr(ord(c)+key) if c != ' 'else ' ' for c in txt])

def decrypt(txt, key):
    key = key % 26
    txt = txt.lower()

if __name__ == '__main__':
    key = 2
    encrTxt = encrypt("we attack at dawn", key)
    plaintTxt = encrypt(encrTxt, key, reverse=True)

    print(plaintTxt)

