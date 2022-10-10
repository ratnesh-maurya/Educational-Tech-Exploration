#Program to check whether the input is Palindrome or not

#Accepting the input
theinput = input("Enter the input: ")

#Reversing the input
reversedinput = theinput[::-1]

#Checking if the reversed input is equal to the original input
if(reversedinput == theinput):
    #Both are equal
    print("Palindrome")
else:
    #Both are not equal
    print("Not Palindrome")