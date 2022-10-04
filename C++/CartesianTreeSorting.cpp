// A C++ program to implement Cartesian Tree sort
#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node *left, *right;
};

typedef pair<int, Node*> iNPair;

void pQBasedTraversal(Node* root)
{
	priority_queue <iNPair, vector<iNPair>, greater<iNPair>> pQueue;
	pQueue.push (make_pair (root->data, root));

	while (! pQueue.empty())
	{
		iNPair popped_pair = pQueue.top();
		printf("%d ", popped_pair.first);

		pQueue.pop();

		if (popped_pair.second->left != NULL)
			pQueue.push (make_pair(popped_pair.second->left->data,
								popped_pair.second->left));

		if (popped_pair.second->right != NULL)
				pQueue.push (make_pair(popped_pair.second->right->data,
									popped_pair.second->right));
	}

	return;
}


Node *buildCartesianTreeUtil(int root, int arr[],
		int parent[], int leftchild[], int rightchild[])
{
	if (root == -1)
		return NULL;

	Node *temp = new Node;

	temp->data = arr[root];
	temp->left = buildCartesianTreeUtil(leftchild[root],
				arr, parent, leftchild, rightchild);

	temp->right = buildCartesianTreeUtil(rightchild[root],
				arr, parent, leftchild, rightchild);

	return temp ;
}

Node *buildCartesianTree(int arr[], int n)
{
	int parent[n], leftchild[n], rightchild[n];

	// Initialize all array values as -1
	memset(parent, -1, sizeof(parent));
	memset(leftchild, -1, sizeof(leftchild));
	memset(rightchild, -1, sizeof(rightchild));

	int root = 0, last;

	for (int i = 1; i <= n - 1; i++)
	{
		last = i-1;
		rightchild[i] = -1;

		while (arr[last] >= arr[i] && last != root)
			last = parent[last];

		if (arr[last] >= arr[i])
		{
			parent[root] = i;
			leftchild[i] = root;
			root = i;
		}

		// Just insert it
		else if (rightchild[last] == -1)
		{
			rightchild[last] = i;
			parent[i] = last;
			leftchild[i] = -1;
		}

		// Reconfigure links
		else
		{
			parent[rightchild[last]] = i;
			leftchild[i] = rightchild[last];
			rightchild[last]= i;
			parent[i] = last;
		}

	}

	parent[root] = -1;

	return (buildCartesianTreeUtil (root, arr, parent,
									leftchild, rightchild));
}

// Sorts an input array
int printSortedArr(int arr[], int n)
{
	// Build a cartesian tree
	Node *root = buildCartesianTree(arr, n);

	printf("The sorted array is-\n");

	pQBasedTraversal(root);
}

/* Driver program to test above functions */
int main()
{

	int arr[] = {5, 10, 40, 30, 28};
	int n = sizeof(arr)/sizeof(arr[0]);

	printSortedArr(arr, n);

	return(0);
}
