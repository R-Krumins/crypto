import random

PLAIN_TEXT = "fuckmeintheass"

removed_char = "j";
replacer_char = "i";
legal_characters = list("abcdefghijklmnopqrstuvwxyz".replace(removed_char, ""))

def newCypherTable():
    ct = list(legal_characters)
    random.shuffle(ct)
    return ct

def printCypherTable(ct):
    for i in range(25):
        if i % 5 == 0: print("\n")
        print(ct[i], end=" ")
    print()

def encrypt (txt, ct):
    #print("--------------")
    txt = txt.replace(removed_char, replacer_char)

    #make sure the text is of even length
    if len(txt) % 2 != 0:
        txt += "a" if "a" != removed_char else "b"
    #split text into chunks of cypherTable indexes
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
       
    return encrTxt


if __name__ == '__main__':
    ct = newCypherTable()
    encryptedText = encrypt(PLAIN_TEXT, ct)
    printCypherTable(ct)
    print(encryptedText)
