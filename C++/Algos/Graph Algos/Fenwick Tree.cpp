#include<bits/stdc++.h>
using namespace std;

vector<int> BIT;
void Update(int idx,int val)
{
    idx++;
    while(idx <= BIT.size())
    {
        BIT[idx] += val;
        idx += idx & (-idx);
    }

}

int Sum_range(int idx)
{
    int sum = 0;
    idx++;
    while(idx > 0)
    {
        sum += BIT[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

void Fenwick_tree(vector<int> arr)
{
    int n = arr.size();
    BIT = vector<int>(n+1,0);

    for(int i = 0;i<n;i++)
    Update(i,arr[i]);
}

int main()
{
    vector<int> arr{1,3,5};

    Fenwick_tree(arr);
    int l,r;
    // for queries

    // Query 1 : Range Sum from arr[0,2]
    l = 0, r = 2;
    if(l == 0)
    cout<<Sum_range(r)<<endl;
    else 
    cout<<Sum_range(r) - Sum_range(l-1)<<endl;

    // Query 2 : Update value at index i to val

    int idx = 1;
    int val = 2;
    int diff = val - arr[idx];

    Update(1,diff);
    arr[idx] = val;
    
    // Query 3 : Range Sum from arr[0,2]
    l = 0, r = 2;
    if(l == 0)
    cout<<Sum_range(r)<<endl;
    else 
    cout<<Sum_range(r) - Sum_range(l-1)<<endl;

    return 0;
}
