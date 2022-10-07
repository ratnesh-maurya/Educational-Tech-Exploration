/*
   it is one of famous game theory problem.
   Problem statement :- You are given an array A[] of n elements. There are two players player 1 and player 2. A player can choose any of element from an array and remove it. If the bitwise XOR of all remaining elements equals 0 after removal of the selected element, then that player loses. Find out the winner if player 1 starts the game and they both play their best.
   Problem link :- https://practice.geeksforgeeks.org/problems/variation-in-nim-game4317/1?page=1&category[]=Game%20Theory&sortBy=submissions

*/

#include <bits/stdc++.h>
using namespace std;

int findWinner(int n, int A[])
{

    if (n % 2 == 0)
    {
        return 1;
    }
    return 2;
}

int main()
{

    int n, i;
    cin >> n;

    int arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];

    int winner = findWinner(n, arr);
    if (winner == 1)
        cout << "Player 1";
    else
        cout << "Player 2";
    return 0;
}