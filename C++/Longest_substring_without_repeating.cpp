class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       
       unordered_set<char> check;
        int i=0,j=0,ans=0;
        while(j<s.length()){
            
            if(check.find(s[j])==check.end())
                check.insert(s[j]);
            else{
               while(check.find(s[j])!=check.end())
                    check.erase(s[i++]);
                check.insert(s[j]);
               
            }
            ans=max(ans,j-i+1),j++;
            
        }
        // ans=max(ans,j-i);
        return ans;
    }
};
