#  Ceaser Cipher
def EnCrpyt(k,s):
    C=list(s)
    print(C)
    l=[]
    f=""
    for i in range(len(C)):
        if C[i].isupper():
            s= (ord(C[i]) + k-65)%26 + 65
        else:
            s=(ord(C[i]) + k-97)%26 + 97
        l.append(chr(s))
    return f.join(l)
def DeCrypt(k,s):
    C=list(s)
    print(C)
    l=[]
    f=""
    for i in range(len(C)):
        if C[i].isupper():
            s= (ord(C[i]) - k-65)%26 + 65
        else:
            s=(ord(C[i]) - k-97)%26 + 97
        l.append(chr(s))
    return f.join(l)
s= 'abcABC'
print(EnCrpyt(2,s))
e='cdeCDE'
print(DeCrypt(2,e))