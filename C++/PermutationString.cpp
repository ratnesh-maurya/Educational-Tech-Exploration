#include <iostream>
using namespace std;

void perm(string s, int k)
{
    static int A[10] = {0};
    static char res[10];
    int i;
    if (s[k] == '\0')
    {
        res[k] = '\0';
        printf("%s\n", res);
    }
    else
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                res[k] = s[i];
                A[i] = 1;
                perm(s, k + 1);
                A[i] = 0;
            }
        }
    }
}
int main()
{
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    perm(str, 0);
    return 0;
}