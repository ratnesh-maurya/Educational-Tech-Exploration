// TIME COMPLEXITY --> O(V+E)
// SPACE COMPLEXITY --> O(V)

// TOPO SORT USING bfs

#include<iostream>
#include<queue>
using namespace std;
void bfs(queue<int> &q, vector<int> &indegree, vector<int> &ans, vector<int> adj[])
{
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        
        for(auto it: adj[node])
        {
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }
}
int main()
{
    int nodes, edges;
    cout << "Enter number of nodes and edges : ";
    cin >> nodes >> edges;

    // adjencency list
    vector<int> adj[nodes];

    cout << "Enter "<< edges << " pairs of src, dest vertices of a edge : ";
    for(int i=0; i< edges; i++) {
        int u,v;
        cin >> u >> v;
        // directed graph
        adj[u].push_back(v);
    }
    
    vector<int> ans;
	   
	vector<int> indegree(nodes, 0);
	
	//finding the indegree of every node
	for(int i = 0; i<nodes; i++)
	{
	    for(auto it: adj[i])
	    {
	        indegree[it]++;
	    }
	}
	
	queue<int> q;
	
	//push all the elements with indegree 0 in the q
	for(int i = 0; i<nodes; i++)
	{
	    if(indegree[i] == 0)
	         q.push(i);
	}
	
	bfs(q, indegree, ans, adj);
	
	// printing the ans
	for(auto it: ans)
	    cout<<it<<" ";
	    
    return 0;
}
