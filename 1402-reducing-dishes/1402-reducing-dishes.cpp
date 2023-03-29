class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i = 0;i < n;i++)
            dp[i][0] = satisfaction[i];

        int maxi = satisfaction[n-1];
        
        for(int i = 1;i < n;i++){
            for(int j = 1;j <= i;j++){
                dp[i][j] = dp[i-1][j-1] + satisfaction[i] * (j+1);
                maxi = max(dp[i][j],maxi);
            }
        }
        if(maxi < 0)
            return 0;
        return maxi;
    }
};