#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define v(num) v.push_back(num)
#define ll long long int
 
 
ll small(vector<vector<char>>&grid)
{
	ll n=grid.size();
	ll m=grid[0].size();
	ll one=5;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<m-1;j++)
		{
			int cnt=0;
			if(grid[i][j]=='1') cnt++;
			if(grid[i+1][j]=='1') cnt++;
			if(grid[i][j+1]=='1') cnt++;
			if(grid[i+1][j+1]=='1') cnt++;
			if(cnt<one) one=cnt;
		}
	}
	return one;
}
 
void solve() {
	// My code goes here
	ll n,m; cin>>n>>m;
	vector<vector<char>>grid(n,vector<char>(m));
	for(auto & row:grid)
	{
		for(auto & cell:row) cin>>cell;
	}
	ll smallest=small(grid);
	ll total=0;
	for(auto & row:grid)
	{
		for(auto & cell:row) 
		{
			if(cell=='1') total++;
		}
	}
	ll ans=0;
	if(smallest==1) ans=1;
	else if(smallest>1) ans=2;
	ans+=total-smallest;
	cout<<ans<<endl;
}
 
int main() 
{
	int testCases; cin>>testCases;
	while(testCases--) {
		solve();
	}
}