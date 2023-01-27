class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n], maxsum;
        dp[0] = nums[0];
        maxsum = nums[0];
        for(int i = 1;i < n;i++){
            dp[i] = max(dp[i-1]+nums[i], nums[i]);  //Pull DP approach
            maxsum = max(dp[i], maxsum);
        }
        return maxsum;
    }
};