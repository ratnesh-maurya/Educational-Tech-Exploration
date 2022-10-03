# Contributor: Sarthak Kapaliya
# Github: TheNobody-12
#  Hill Cipher
import numpy as np
key = "hill".upper()
plaintext = "busy".upper()
print("Key used :"+key+"\n","Plaintext: "+plaintext)
aplha = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
key = list(key)
plaintext = list(plaintext)
def createMatrix(key):    
    for i in range(len(key)):
        if key[i] in aplha:
            key[i] = aplha.index(key[i])
    key = np.array(key).reshape(2,2)
    return key
key1=createMatrix(key)
def encrypt(key,plaintext):
    plaintext = createMatrix(plaintext)
    key = createMatrix(key)
    p1 = plaintext[0]
    p2 = plaintext[1]
    c1 = np.dot(key,p1)%26
    c2 = np.dot(key,p2)%26
    cipher=[]
    for i in range(len(c1)):
        cipher.append(aplha[c1[i]])
    for i in range(len(c2)):
        cipher.append(aplha[c2[i]])
    return cipher
print("Encrypted Mssg : " + "".join(encrypt(key,plaintext)))
adj = np.array([[key1[1][1],-key1[0][1]],[-key1[1][0],key1[0][0]]])
adj = adj%26
det = key1[0][0]*key1[1][1]-key1[0][1]*key1[1][0]
def mod_Inv(x,y):
    for i in range(y):
        if (x*i)%y==1:
            return i
keyInv = (mod_Inv(det,26) * adj)%26
ctext = encrypt(key,plaintext)
def decrypt(key,ciphertext):
    ciphertext = createMatrix(ciphertext)
    key = createMatrix(key)
    p1 = ciphertext[0]
    p2 = ciphertext[1]
    c1 = np.dot(keyInv,p1)%26
    c2 = np.dot(keyInv,p2)%26
    plaintext=[]
    for i in range(len(c1)):
        plaintext.append(aplha[c1[i]])
    for i in range(len(c2)):
        plaintext.append(aplha[c2[i]])
    return plaintext
print("Decrypted Mssg : "+ "".join(decrypt(key,ctext)))




    

