
#include <bits/stdc++.h>
using namespace std;

int findDiff(int arr[], int n)
{
	unordered_map<int, int> hm;
	for (int i = 0; i < n; i++)
		hm[arr[i]]++;
	int max_count = 0, min_count = n;
	for (auto x : hm) {
		max_count = max(max_count, x.second);
		min_count = min(min_count, x.second);
	}

	return (max_count - min_count);
}

int main()
{
	int arr[] = { 7, 8, 4, 5, 4, 1, 1, 7, 7, 2, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << findDiff(arr, n) << "\n";
	return 0;
}
