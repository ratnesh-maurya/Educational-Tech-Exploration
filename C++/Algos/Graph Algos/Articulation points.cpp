#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> adj,vector<int> &low,vector<int> &parent,vector<int> &dist,int u,vector<bool> &art)
{
  static int time = 0;
  dist[u] = low[u] = time;
  time++;
  int child = 0;
  for(auto v : adj[u])
  {
    if(dist[v] == -1)
    {
      child++;
      parent[v] = u;
      dfs(adj,low,parent,dist,v,art);
      low[u] = min(low[u],low[v]);

      if(parent[u] == -1 && child > 1)
      art[u] = true;
      
      if(parent[u] != -1 && low[v] >= dist[u])
      art[u] = true;
    }
    else if(v != parent[u])
    low[u] = min(low[u],dist[v]);
  }
}
void Articulation_points(vector<vector<int>> adj,int v)
{
  vector<int> low(v,-1),parent(v,-1),dist(v,-1);
  vector<bool> art(v,false);
  for(int i = 0;i<v;i++)
  {
    if(dist[i] == -1)
    dfs(adj,low,parent,dist,i,art);
  }

  cout<<"Articulation Points : ";
  for(int i = 0;i<v;i++)
  {
    if(art[i])
    cout<<i<<" ";
  }
  cout<<endl;
}



int main()
{
  int v = 5;
  vector<vector<int>> adj(v);
  adj[0].push_back(2);
	adj[2].push_back(0);
	adj[0].push_back(3);
	adj[3].push_back(0);
	adj[1].push_back(0);
	adj[0].push_back(1);
	adj[2].push_back(1);
	adj[1].push_back(2);
	adj[3].push_back(4);
	adj[4].push_back(3);

  Articulation_points(adj,v);

}
