// CPP code to verify Euler's four-square identity
#include<bits/stdc++.h>
using namespace std;

// This function prints the four numbers if a solution is found Else prints solution doesn't exist
void checkEulerFourSquareIdentity(int a, int b)
{
	// Number for which we want to find a solution
	int ab = a * b;
	bool flag = false;
	
	int i = 0;
	while(i * i <= ab) // loop for first number
	{
		int j = i;
		while (i * i + j * j <= ab) // loop for second number
		{
			int k = j;
			while(i * i + j * j +
				k * k <= ab) // loop for third number
			{
				// Calculate the fourth number and apply square root
				double l = sqrt(ab - (i * i + j *
										j + k * k));
				
				// Check if the fourthNum is Integer or not. If yes, then solution is found
				if (floor(l) == ceil(l) && l >= k)
				{
					flag = true;
					cout<<"i = " << i << "\n";
					cout<<"j = " << j << "\n";
					cout<<"k = " << k << "\n";
					cout<<"l = " << (int)l << "\n";
					cout<<"Product of " << a << " and "<< b <<
								" can be written as sum of squares"<<
												" of i, j, k, l \n";
												
					cout<<ab + " = " << i << "*" << i << " + " <<
										j << "*" << j<< " + " << k << "*" <<
											k << " + " << (int)l << "*" <<
														(int)l << "\n";
					
				}
				k += 1;
			}
			j += 1;
		}
		i += 1;
	}
	
	// Solution cannot be found
	if (flag == false)
	{
		cout<< "Solution doesn't exist!\n";
		return ;
	}
}

// Code
int main()
{
	int a = 30;
	int b = 4;
	checkEulerFourSquareIdentity(a, b);
	return 0;
}

// This code is contributed by Abhay Gupta
