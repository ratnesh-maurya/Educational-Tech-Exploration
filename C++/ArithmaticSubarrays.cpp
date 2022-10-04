class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool> answer;
        int m = l.size();
        int n =nums.size();
        bool t;
        
        for(int i =0 ;i<m ;i++){
            t = true;
            vector<int> ans;
             for(int j=l[i] ;j<=r[i];j++){
                 ans.push_back(nums[j]);
             }
            sort(ans.begin() , ans.end());
            
            int a =ans.size();
            int diff = ans[1] - ans[0];
            for(int k =1 ;k<a ;k++){
                if((ans[k]-ans[k-1])!=diff){
                    t = false;
                    break;
                }
            }
           answer.push_back(t); 
        }
       return answer; 
    }
};