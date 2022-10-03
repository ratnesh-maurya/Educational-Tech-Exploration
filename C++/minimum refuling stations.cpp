class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        priority_queue<int> pq;
        int far=startFuel,i=0,count=0;
        while(far<target){
            while(i<stations.size() && far>=stations[i][0])
                pq.push(stations[i++][1]);
            if(pq.empty())
                return -1;
            far+=pq.top();
              pq.pop();
             count++;
          
        }
        return count;
        
    }
};
