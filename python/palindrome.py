#Program to check whether the input is Palindrome or not

#Accepting the Input
theinput = input("Enter the input: ")

#Reversing the Input
reversedinput = theinput[::-1]

#Checking if the reversed input is equal to the original input
if(reversedinput == theinput):
    #Both are Equal
    print("Palindrome")
else:
    #Both are not Equal
    print("Not Palindrome")