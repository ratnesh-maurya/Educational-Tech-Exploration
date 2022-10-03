// C++ Program to perform 3 way Merge Sort

#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &gArray, int low, int mid1,
		int mid2, int high, vector<int> &destArray)
{
	int i = low, j = mid1, k = mid2, l = low;

	// Choose smaller of the smallest in the three ranges
	while ((i < mid1) && (j < mid2) && (k < high))
	{
		if(gArray[i] < gArray[j])
		{
			if(gArray[i] < gArray[k])
			{
				destArray[l++] = gArray[i++];
			}
			else
			{
				destArray[l++] = gArray[k++];
			}
		}
		else
		{
			if(gArray[j] < gArray[k])
			{
				destArray[l++] = gArray[j++];
			}
			else
			{
				destArray[l++] = gArray[k++];
			}
		}
	}

	// Case where first and second ranges
	// have remaining values
	while ((i < mid1) && (j < mid2))
	{
		if(gArray[i] < gArray[j])
		{
			destArray[l++] = gArray[i++];
		}
		else
		{
			destArray[l++] = gArray[j++];
		}
	}

	while ((j < mid2) && (k < high))
	{
		if(gArray[j] < gArray[k])
		{
			destArray[l++] = gArray[j++];
		}
		else
		{
			destArray[l++] = gArray[k++];
		}
	}
	while ((i < mid1) && (k < high))
	{
		if(gArray[i] < gArray[k])
		{
			destArray[l++] = gArray[i++];
		}
		else
		{
			destArray[l++] = gArray[k++];
		}
	}

	// Copy remaining values from the first range
	while (i < mid1)
		destArray[l++] = gArray[i++];

	// Copy remaining values from the second range
	while (j < mid2)
		destArray[l++] = gArray[j++];

	// Copy remaining values from the third range
	while (k < high)
		destArray[l++] = gArray[k++];
}

void mergeSort3WayRec(vector<int> &gArray, int low,
					int high, vector<int> &destArray)
{
	// If array size is 1 then do nothing
	if (high - low < 2)
		return;

	// Splitting array into 3 parts
	int mid1 = low + ((high - low) / 3);
	int mid2 = low + 2 * ((high - low) / 3) + 1;

	// Sorting 3 arrays recursively
	mergeSort3WayRec(destArray, low, mid1, gArray);
	mergeSort3WayRec(destArray, mid1, mid2, gArray);
	mergeSort3WayRec(destArray, mid2, high, gArray);

	// Merging the sorted arrays
	merge(destArray, low, mid1, mid2, high, gArray);
}

void mergeSort3Way(vector<int> &gArray, int n)
{
	// if array size is zero return null
	if (n == 0)
		return;

	// creating duplicate of given array
	vector<int> fArray(n);

	// copying elements of given array into
	// duplicate array
	for (int i = 0; i < n; i++)
		fArray[i] = gArray[i];

	// sort function
	mergeSort3WayRec(fArray, 0, n, gArray);

	// copy back elements of duplicate array
	// to given array
	for (int i = 0; i < n; i++)
		gArray[i] = fArray[i];
}

// Driver Code
int main()
{
	vector<int> data = {45, -2, -45, 78, 30,
				-42, 10, 19, 73, 93};
	mergeSort3Way(data,10);
	cout << "After 3 way merge sort: ";
	for (int i = 0; i < 10; i++)
	{
		cout << data[i] << " ";
	}
	return 0;
}
