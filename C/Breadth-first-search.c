// C program to implement Breadth First Search in C

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void bfs(int m[SIZE][SIZE],int v,int source);

void main()
{
   int v,m[SIZE][SIZE],i,j,source;
   printf("enter the number of vertices=");
   scanf("%d",&v);
   printf("enter the graph in the form of matrix\n");
   for(i=0;i<v;i++)
    {
    for(j=0;j<v;j++)
      {
      scanf("%d",&m[i][j]);
      }
    }
   printf("enter the source vertex=");
   scanf("%d",&source);
   bfs(m,v,source);
}


void bfs(int m[SIZE][SIZE],int v,int source)
{
 int queue[20],front=0,rear=0,u,i;
 int visited[10];
 for(i=0;i<v;i++)
  {
    visited[i]=0;
  }
queue[rear]=source;
visited[source]=1;
printf("THE BFS TRAVERSAL IS \n");
while(front<=rear)
  {
  u=queue[front];
  printf("%d\t",u);
  front=front+1;
  for(i=0;i<v;i++)
   {
    if(m[u][i]==1 && visited[i]==0)
    {
      visited[i]=1;
      rear=rear+1;
      queue[rear]=i;
    }
   }
  }
}
