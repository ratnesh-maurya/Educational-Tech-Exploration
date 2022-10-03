/*

Dijkstra's Shortest Path Algorithm

Given a graph and a source vertex in the graph, find the shortest paths from the source vertex to all vertices in the given graph.

Time Complexity : O(V + ElogV)
Space Complexity : O(V + E)

Practice Problem Links :
https://codeforces.com/contest/20/problem/C
https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

My profile link : https://leetcode.com/abhi__ram/

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
const long long inf = 1e18;

struct Dijkstra{
    int n;
    vector<int> visited;
    vector<int> dist;
    vector<int> parent;
    vector<vector<pair<int, int>>> adj;

    Dijkstra(vector<vector<pair<int, int>>> adj, int n){
        this->adj = adj;
        this->n = n;
        visited.resize(n, false);
        dist.resize(n, inf);
        parent.resize(n, -1);
    }

    vector<int> dijkstra(int start){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, start});
        dist[start] = 0;
        while (!q.empty()){
            int curr_u = q.top().second;
            q.pop();
            if (visited[curr_u]) continue;
            visited[curr_u] = 1;

            for (auto &ele : adj[curr_u]){
                int curr_v = ele.first;
                int new_w = ele.second;
                if (!visited[curr_v] && dist[curr_u] + new_w < dist[curr_v]){
                    dist[curr_v] = dist[curr_u] + new_w;
                    parent[curr_v] = curr_u;
                    q.push({dist[curr_v], curr_v});
                }
            }
        }
        return dist;
    }
};

int32_t main(){

    int V, E,source;
    cin >> V >> E >> source;
    vector<vector<pair<int,int>>> adj(V);

    for(int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    struct Dijkstra D(adj,V);
    vector<int> dist = D.dijkstra(source);
    for( int i = 0; i < V; i++) cout << dist[i] << " ";
   
    return 0;
}
