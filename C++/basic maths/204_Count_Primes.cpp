//Count Primes - Leetcode
//Leetcode Link : https://leetcode.com/problems/count-primes/submissions/

class Solution {
public:
    int countPrimes(int n) {
        
        int count = 0;
        vector<bool> v(n+1, true);
        
        v[0] = false;
        v[1] = false;
        
        for(int i = 2; i<n ; i++){
            
            if(v[i]){
                count++;
                for(int j = 2*i; j<n; j=j+i){
                    v[j] = 0;
                }
            }
        }
        return count;
    }
};