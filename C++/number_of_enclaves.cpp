class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
     int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int count=0;
        int tot_count=0;
        for(int i=0;i<n;i++)
        {      if(grid[i][0]==1&&vis[i][0]==0)
        { vis[i][0]=1;
          q.push({i,0});
        }
        if(grid[i][m-1]==1&&vis[i][m-1]==0)
        {vis[i][m-1]=1;
         q.push({i,m-1});
        }
        }
        for(int j=1;j<m-1;j++)
        {   
            if(grid[0][j]==1&&vis[0][j]==0)
            {vis[0][j]=1;
            q.push({0,j});
            }
         if(grid[n-1][j]==1&&vis[n-1][j]==0)
         {vis[n-1][j]=1;
         q.push({n-1,j});
         }
        }
        
        count=q.size();

        int delrow[]={-1,+1,0,0};
        int delcol[]={0,0,+1,-1};
        while(!q.empty())
        {
            int nrow=q.front().first;
            int ncol=q.front().second;
            
            q.pop();
           if(nrow+1<n&&ncol<m&&vis[nrow+1][ncol]==0&&grid[nrow+1][ncol]==1)//down
           { count++;
            vis[nrow+1][ncol]=1;
            q.push({nrow+1,ncol});
            cout<<"down"<<endl;
           } 
              if(nrow-1>=0&&ncol>=0&&vis[nrow-1][ncol]==0&&grid[nrow-1][ncol]==1)//up
           { count++;
            vis[nrow-1][ncol]=1;
            q.push({nrow-1,ncol});
                 cout<<"up"<<endl;
           } 
              if(nrow<n&&ncol+1<m&&vis[nrow][ncol+1]==0&&grid[nrow][ncol+1]==1)//right
           { count++;
            vis[nrow][ncol+1]=1;
                q.push({nrow,ncol+1});
                 cout<<"right"<<endl;
           } 
              if(nrow>=0&&ncol-1>=0&&vis[nrow][ncol-1]==0&&grid[nrow][ncol-1]==1)//left
           { count++;
            vis[nrow][ncol-1]=1;
            q.push({nrow,ncol-1});
                 cout<<"left"<<endl;
           } 
             
             
                
            
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    tot_count++;
            }
        }
        cout<<"totcount"<<tot_count<<endl;
        cout<<count;
                return tot_count-count;
    }
};
