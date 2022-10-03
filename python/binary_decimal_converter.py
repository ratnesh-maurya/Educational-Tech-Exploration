import os
output = ""
   
def binarytodecimal(value):
    global output
    binary1 = value
    decimal, i, n = 0, 0, 0
    while(value != 0):
        dec = int(value) % 10
        decimal = decimal + dec * pow(2, i)
        value = int(value)//10
        i += 1
    output = decimal

def decimaltobinary(value):
    global output
    if(value > 1):
        decimaltobinary(value//2)
    output += str(value%2)

def prompt():
        os.system('cls')
        print("\t\t\t***Binary/Decimal convertor***")
        print("\n1. Binary to Decimal")
        print("2. Decimal to Binary\n")
        choice = input("Enter your choice : ")
        if(choice=='1'):
            binary = input("Enter a binary string : ")
            binarytodecimal(binary)
            print(output)
        elif(choice=='2'):
            decimal = input("Enter a Decimal number : ")
            decimaltobinary(decimal)
            print(output)
        else:
            print("Enter a valid option")
            os.system('cls')
            prompt()

if __name__=="__main__":
    prompt()
        
