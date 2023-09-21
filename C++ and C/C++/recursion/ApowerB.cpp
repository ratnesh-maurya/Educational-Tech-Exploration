#include <bits/stdc++.h>
using namespace std;


int ApowerB(int a, int b) {
	//base case
	if (b == 0)
		return 1;

	if (b == 1)
		return a;

	//Recursive call
	int ans = ApowerB(a, b / 2);

	//if b is even
	if (b % 2 == 0) {
		return ans * ans;
	}
	else {
		return a * ans * ans;
	}
}
int main()
{
    int a, b;
    cin >> a >> b;
    
    cout << ApowerB(a, b);
    return 0;
}