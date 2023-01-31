class Solution {
public:
    //Recursive soln
//     int fib(int n) {
//         if(n <= 1){
//             return n;
//         }
        
//         return fib(n-1)+fib(n-2);
//     }
    
    //Memoized solution
//     int fib_mem(int n, vector<int> &dp) {
        
//         if(n <= 1){
//             return n;
//         }
        
//         if(dp[n] != -1){   //If already the subproblem was solved and memoized before 
//             return dp[n];
//         }
        
//         return dp[n] = fib_mem(n-1,dp)+fib_mem(n-2,dp);
//     }
    
    // int fib(int n){
    //     vector<int> dp(n+1, -1);  //n+1, since 0 is also included
    //     return fib_mem(n,dp);     //Time complexity -> O(n), Space Complexity -> O(n)(rec stack) + O(n)
    // }
    
    //Tabulation solution
//     int fib(int n){
//         vector<int> dp(n+1, -1);
//         dp[0] = 0;  //base cases from the recursion
//         dp[1] = 1;
        
//         for(int i = 2;i <= n;i++){
//             dp[i] = dp[i-1]+dp[i-2];
//         }
//         return dp[n];        //TC -> O(n), SC -> O(n) (for the dp array)
//     }
    
    //Space optimized solution
    int fib(int n){
        int prev2,prev;
        if(n <= 1){
            return n;
        }
        prev2 = 0;  //instead of dp[0]
        prev = 1;   //instead of dp[1]
        
        for(int i = 2;i <= n;i++){
            int curr = prev + prev2;  //dp[i] = dp[i-1]+dp[i-2]
            prev2 = prev;
            prev = curr;
        }
        return prev;    //TC -> O(n), SC -> O(1)
    }
};