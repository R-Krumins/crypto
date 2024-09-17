import itertools
import random
import json

legal_characters = list("abcdefghijklmnopqrstuvwxyz ")
cypherTable_fileName = "cypherTable.json"

def newCypherTable(blockSize):
    plainBlocks = [''.join(perm) for perm in itertools.product(legal_characters, repeat=blockSize)]
    cypherBlocks = list(plainBlocks)
    random.shuffle(cypherBlocks)
    cypherTable = dict(zip(plainBlocks, cypherBlocks))
    return cypherTable

def saveCypherTable(cypherTable):
    with open(cypherTable_fileName , "w") as file:
        json.dump(cypherTable, file)

def loadCypherTable():
    with open(cypherTable_fileName , 'r') as file:
        cypherTable = json.load(file)
    return cypherTable

def encryptText(plainText, cypherTable, blockSize):
   
    #make sure plainText is divisable by blockSize
    if len(plainText) % blockSize != 0:
        nMore = blockSize - (len(plainText) % blockSize) 
        plainText += "a" * nMore
        
    blocks = [plainText[i:i+blockSize] for i in range(0, len(plainText), blockSize)]
    encryptedText = [cypherTable[b] for b in blocks]
    return "".join(encryptedText)


plainText = "big titty goth gf now"
blockSize = 8

#ct = loadCypherTable();
#encrypted = encryptText(plainText, ct, blockSize)
#print(encrypted)

ct = newCypherTable(blockSize)
saveCypherTable(ct)
