#include<bits/stdc++.h>
using namespace std;

// Disjoint Set Union by rank and path compression
struct node{
        int parent;
        int rank;
    };
vector<node> dsuf;
int Find(int v)
{
    if(dsuf[v].parent == -1)
        return v;
    return dsuf[v].parent = Find(dsuf[v].parent);
}
void Union(int x,int y)
{
    if(dsuf[x].rank == dsuf[y].rank)
    {
        dsuf[x].parent = y;
        dsuf[y].rank++;
    }
    else if(dsuf[x].rank < dsuf[y].rank)
        dsuf[x].parent = y;
    else 
        dsuf[y].parent = x;
}

// Minimum Spanning Tree
bool sortby_mst(vector<int> &a,vector<int> &b)
{
    return a[2] < b[2];
}
void kruskal_mst(vector<vector<int>> &edge_list,int V)
{
    sort(edge_list.begin(),edge_list.end(),sortby_mst);
    dsuf.resize(V);
    for(int i = 0;i<V;i++)
    {
        dsuf[i].rank = 0;
        dsuf[i].parent = -1;
    }
    int i = 0;
    int j = 0;
    vector<vector<int>> mst;
    while(i < V-1 && j < edge_list.size())
    {
        int xp = Find(edge_list[i][0]);
        int yp = Find(edge_list[i][1]);
        if(xp == yp)
        {
            j++;
            continue;
        }
        Union(xp,yp);
        mst.push_back(edge_list[i]);
        i++;
    }

    cout<<"Minimum spanning tree as (u,v,dis) :"<<endl;
    for(int i = 0;i<mst.size();i++)
    cout<<mst[i][0]<<" "<<mst[i][1]<<" "<<mst[i][2]<<endl;
}


int main()
{
    int V = 6;
    vector<vector<int>> edge_list{
        {0,1,4},
        {1,4,4},
        {1,2,6},
        {1,3,3},
        {0,2,6},
        {2,3,1},
        {4,5,7},
        {4,3,2},
        {3,5,3},
    };
    // where edge_list[i] = {u,v,dis} 
    kruskal_mst(edge_list,V);

}
