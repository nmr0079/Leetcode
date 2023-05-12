class Solution {
public:
    //Recursive Solution
//     long long maxPoints(vector<vector<int>>& questions, int index){
//         if(index == questions.size() - 1)
//             return questions[questions.size() - 1][0];
//         if(index >= questions.size())
//             return 0;
        
//         long long solve = questions[index][0] + maxPoints(questions, index + questions[index][1] + 1);
//         long long not_solve = maxPoints(questions, index+1);
//         return max(solve, not_solve);
//     }
    
//     //Memoized Solution
//     long long maxPoints(vector<vector<int>>& questions, int index, vector<int>& dp){
//         if(index == questions.size() - 1)
//             return questions[questions.size() - 1][0];
//         if(index >= questions.size())
//             return 0;
//         if(dp[index] != -1)
//             return dp[index];
//         long long solve = questions[index][0] + maxPoints(questions, index + questions[index][1] + 1, dp);
//         long long not_solve = maxPoints(questions, index+1, dp);
//         return dp[index] = max(solve, not_solve);
//     }
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        dp[n-1] = questions[n-1][0];
        
        for(int i = n-2; i >= 0;i--){
            long long solve = questions[i][0];
            if(i+questions[i][1]+1 < n)
                solve += dp[i+questions[i][1]+1];
            long long not_solve = dp[i+1];
            dp[i] = max(solve, not_solve);
        }
        return dp[0];
    }
};