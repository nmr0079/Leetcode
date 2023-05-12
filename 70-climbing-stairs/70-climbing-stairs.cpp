class Solution {
public:
//     int climbStairs(int n) {
//         if(n == 0 || n == 1){
//             return 1;
//         }
        
//         int prev2,prev;
//         prev2 = 1;
//         prev = 1;
//         for(int i = 2;i <= n;i++){
//             int curr = prev2 + prev;
//             prev2 = prev;
//             prev = curr;
//         }
        
//         return prev;
//     }
    int distinctWays(int n, vector<int>&dp){
        if(n == 1 || n == 0)
             return 1;
         if(n < 0)
             return 0;
        if(dp[n] != -1)
            return dp[n];
         
         return dp[n] = distinctWays(n-1, dp) + distinctWays(n-2, dp);
    }
     int climbStairs(int n) {
         vector<int> dp(n+1, -1);
         return distinctWays(n, dp);
     }
};