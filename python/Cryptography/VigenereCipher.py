# Contributor: Sarthak Kapaliya
# Github: TheNobody-12
#  Vigenere Cipher
# Keyword    : DECEPTIVE
# Key        : DECEPTIVEDECEPTIVEDECEPTIVE
# Plaintext  : WEAREDISCOVEREDSAVEYOURSELF
# Ciphertext : ZICVTWQNGRZGVTWAVZHCQYGLMGJ
aplha="abcdefghijklmnopqrstuvwxyz"
plaintext="wearediscoveredsaveyourself"
key = "deceptive"
def repeat(s,l):
    return (s*(l//len(s)))+s[:l%len(s)]
new=repeat(key,len(plaintext))
# print("Plaintext"+plaintext)
# print(new)
def keyIndex(key):
    keyIndex=[]
    for i in range(len(key)):
        keyIndex.append(aplha.index(key[i]))
    return keyIndex
w = keyIndex(new)
def encrypt(plaintext,new):
    ciphertext=""
    for i in range(len(plaintext)):
        if plaintext[i].isupper():
            ciphertext += chr((ord(plaintext[i]) + new[i] - 65) % 26 + 65)
        else:
            ciphertext += chr((ord(plaintext[i]) + new[i] - 97) % 26 + 97)
    return ciphertext
print("Encrypted : "+encrypt(plaintext,w))


def decryptCipher(str, new):
    keyIndex = new
    plaintext = ""
    for i in range(len(str)):
        if str[i].isupper():
            plaintext += chr((ord(str[i]) - keyIndex[i] - 65) % 26 + 65)
        else:
            plaintext += chr((ord(str[i]) - keyIndex[i] - 97) % 26 + 97)
    return plaintext
print("Decrypted: "+decryptCipher(encrypt(plaintext,w),w))