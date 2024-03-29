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
//     //Memoized Recursive Solution
//     int distinctWays(int n, vector<int>&dp){
//         if(n == 1 || n == 0)
//              return 1;
//          if(n < 0)
//              return 0;
//         if(dp[n] != -1)
//             return dp[n];
         
//          return dp[n] = distinctWays(n-1, dp) + distinctWays(n-2, dp);
//     }
//      int climbStairs(int n) {
//          vector<int> dp(n+1, -1);
//          return distinctWays(n, dp);
//      }
    //Tabulation/BottomUp/DynamicProg
    // int climbStairs(int n) {
    //       vector<int> dp(n+1);
    //       dp[0] = dp[1] = 1;
    //       for(int i = 2;i <= n;i++){
    //           dp[i] = dp[i-1] + dp[i-2];
    //       }
    //       return dp[n];
    //   }
      //Space Optimized
      int climbStairs(int n) {
          int prev2, prev1, curr;
          prev2 = prev1 = 1;
          for(int i = 2;i <= n;i++){
              curr = prev1 + prev2;
              prev2 = prev1;
              prev1 = curr;
          }
          return prev1;
      }
};