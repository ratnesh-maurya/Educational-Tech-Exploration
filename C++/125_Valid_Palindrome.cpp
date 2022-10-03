//                  Valid Palindrome

// Leetcode 125 :: https://leetcode.com/problems/valid-palindrome/

// Brute Force Approach
// TC :: O(n)   SC :: O(1)

bool isPalindrome(string s)
{

    string ans;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        if (int(c) > 64 and int(c) < 91) // ASCII value of A-Z
            ans += tolower(c);

        else if (int(c > 96 and int(c) < 123)) // ASCII value of a-z
            ans += c;

        else if (int(c) >= 48 and int(c) <= 57) // ASCII value of 0-9
            ans += c;
    }
    string copy = ans;
    reverse(copy.begin(), copy.end());
    cout << copy << endl;
    cout << ans << endl;

    return copy == ans;
}

// Best Approach using "isalnum"
// TC :: O(n)   SC :: O(1)

bool isPalindrome(string s)
{
    string str = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (isalnum(s[i])) // check if a character is alphanumeric or not
            str.push_back(tolower(s[i]));
    }
    for (int i = 0; i < str.size() / 2; i++)
    {
        if (str[i] != str[str.size() - 1 - i]) // if str is a palindrome then this condition would always be false
            return false;
    }
    return true;
}