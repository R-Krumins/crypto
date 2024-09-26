from random import shuffle
from re import sub

PLAIN_TEXT = "fuckmeintheass"

#since the 5x5 cypher table contains 25 letters but
#the english alphabet has 26 letters, 1 letter must removed from the plain text
removed_char = "j";
replacer_char = "i";
#the plaintext cannot have conecutive same letters,
#so a bogus letter must be inserted
bogus_char = "x";

legal_characters = list("abcdefghijklmnopqrstuvwxyz".replace(removed_char, ""))

def newRandomCypherTable():
    ct = list(legal_characters)
    shuffle(ct)
    return ct

def createCypherTable(password):
    ct = []
    ct.extend(list(password))
    for x in legal_characters:
        if(x not in password):
           ct.append(x)

    return ct

def printInfo(txt, encrTxt, ct):
    print("PLAIN:", txt)
    print("ENCRYPTED:", encrTxt)
    print("CYPHER TABLE:")
    for i in range(0, 25, 5):
        print("|",ct[i], ct[i+1], ct[i+2], ct[i+3], ct[i+4], "|")

def processPlainText(txt):
    txt = txt.replace(" ", "")
    txt = txt.lower()

    #replace removed character
    txt = txt.replace(removed_char, replacer_char)
    #insert bogus char between consecutive same letters 
    txt = sub(r'(\w)\1', r'\1'+bogus_char+r'\1', txt)

    #make sure the text is of even length
    if len(txt) % 2 != 0:
        txt += "a" if "a" != removed_char else "b"


    return txt;

def encrypt (txt, password):
    txt = processPlainText(txt) 
    ct = createCypherTable(password)

    #split text into chunk pairs of cypherTable indexes
    chunks = []
    for i in range(0, len(txt), 2):
        indexTuple = (ct.index(txt[i]), ct.index(txt[i+1])) 
        chunks.append(indexTuple)
    
    encrTxt = ""
    for i1, i2 in chunks:
       #in the same column
        if abs(i1-i2)%5==0:
            encrTxt += ct[i1+5] if i1+5 < 25 else ct[i1%5]   
            encrTxt += ct[i2+5] if i2+5 < 25 else ct[i2%5]   
            #print("col:", i1, ct[i1], i2, ct[i2])
        #in the same row
        elif i1//5 == i2//5:
            encrTxt += ct[i1+1] if (i1+1)%5!=0 else ct[i1-4]
            encrTxt += ct[i2+1] if (i2+1)%5!=0 else ct[i2-4]
            #print("row:", i1, ct[i1], i2, ct[i2])
        #forms a square
        else:
            offset = abs(i1%5-i2%5)
            if i1%5 > i2%5: offset *= -1
            encrTxt += ct[i1+offset]
            encrTxt += ct[i2-offset]
            #print("sqr:", offset, i1, ct[i1], i2, ct[i2])
    printInfo(txt, encrTxt, ct) 
    return encrTxt

def decrypt(encrTxt, password):
    ct = createCypherTable(password)
    #split text into chunk pairs of cypherTable indexes

    chunks = []
    for i in range(0, len(encrTxt), 2):
        indexTuple = (ct.index(encrTxt[i]), ct.index(encrTxt[i+1])) 
        chunks.append(indexTuple)
    
    plainTxt = ""
    for i1, i2 in chunks:
       #in the same column
        if abs(i1-i2)%5==0:
            plainTxt += ct[i1-5] if i1-5 >= 0 else ct[i1+20]   
            plainTxt += ct[i2-5] if i2-5 >= 0 else ct[i2+20]   
            #print("col:", i1, ct[i1], i2, ct[i2])
        #in the same row
        elif i1//5 == i2//5:
            plainTxt += ct[i1-1] if (i1)%5!=0 else ct[i1+4]
            plainTxt += ct[i2-1] if (i2)%5!=0 else ct[i2+4]
            #print("row:", i1, ct[i1], i2, ct[i2])
        #forms a square
        else:
            offset = abs(i1%5-i2%5)
            if i1%5 > i2%5: offset *= -1
            plainTxt += ct[i1+offset]
            plainTxt += ct[i2-offset]

    plainTxt = sub(r'([a-zA-Z])x\1', r'\1\1', plainTxt)
    return plainTxt


if __name__ == '__main__':
    encryptedText = encrypt("hello world", "playfir")
    plainTxt = decrypt(encryptedText, "playfir")
    print(plainTxt)
