#define ll long long

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        
        int n=arr.size();
        
        vector<map<long long,int>>dp(n);
        
        //  dp[1][2]  means till the index 2 how many sequence we have diffrence 1
        
        // you can make unordered_map 
        
        int res=0;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<i;j++){
                
                
             long long diff=(long long)arr[i]-(long long)arr[j];
                
                
                if(diff<=INT_MIN or diff>=INT_MAX)continue;
                
                int add=0;
                
                if(dp[j].find(diff)!=dp[j].end()){
                    
                    add=dp[j][diff];
                }
                
                dp[i][diff]+=add+1;
                
                res+=add;
                
            }
        }
        
        return (int)res;
        
    }
};