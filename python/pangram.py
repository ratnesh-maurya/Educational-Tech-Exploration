# fn to check if a string is Pangram or not
# Time Complexity = O(n) & Space Complexity = O(1)
def ispangram(string1):
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    for char in alphabet:
        if char not in string1.lower():
            return False
    return True


# Driver's Code
string1 = "abcdefghijklmnopqrstuvxyz"

if ispangram(string1):
    print("Given string is pangram")
else:
    print("Given string is not a pangram")
