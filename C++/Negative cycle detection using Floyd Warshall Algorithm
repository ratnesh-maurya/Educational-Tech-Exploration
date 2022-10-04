#include<bits/stdc++.h>
using namespace std;
#define V 4
#define INF 999999
bool isNegCycle(int graph[][V]){
int dist[V][V];
for(int i=0;i<V;i++)
{

    for(int j=0;j<V;j++)
        dist[i][j]=graph[i][j];
}
for(int k=0;k<V;k++)
{

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
}
for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
    if(dist[i][j]<0)
    return true;
}
return false;


}
int main()
{
     int graph[V][V] = { {0   , 1   , INF , INF},
                        {INF , 0   , -1  , INF},
                        {INF , INF , 0   ,  -1},
                        {-1  , INF , INF ,   0}};
                        if(isNegCycle(graph))
                            cout<<"\nTrue\n";
                        else cout<<"\nFalse\n";
                        return 0;
}
