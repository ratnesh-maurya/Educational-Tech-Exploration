void dfs(vector<int> &parent,vector<int> &low,vector<int> &disco,vector<bool> &visited,int sr,vector<vector<int>> &ans,int &time,vector<vector<int>> &graph){
        
    
        visited[sr]=true;
        disco[sr]=low[sr]=time++;
        for(auto x:graph[sr]){
            if(parent[sr]==x)
                continue;
            else if(visited[x]==true){
                low[sr]=min(low[sr],disco[x]);
                continue;
            }
            
            else{
                parent[x]=sr;
               dfs(parent,low,disco,visited,x,ans,time,graph);
               
                low[sr]=min(low[sr],low[x]);
                
                
                if(low[x]>disco[sr]){
                    ans.push_back({x,sr});
                }
                
                
            }
        }
        
        return ;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       
        vector<vector<int>> graph(n);
        for(int i=0;i<connections.size();i++){
        graph[connections[i][0]].push_back(connections[i][1]);
       graph[connections[i][1]].push_back(connections[i][0]);
        
        }
     
        vector<int> parent(n,-1);
        vector<int> low(n,INT_MAX);
        vector<int> disco(n,INT_MAX);
        vector<bool> visited(n,false);
        vector<vector<int>> ans;
        int time=0;
        
        
        dfs(parent,low,disco,visited,0,ans,time,graph);
        
        return ans;
        
    }
