class Solution {
public:
    //Memoized solution
    int rec_fn(int ind, int prev_ind, vector<int>& nums, vector<vector<int>>& dp){ //prev_ind->index of previous element 
        //base case
        if(ind == nums.size())
            return 0;
        if(dp[ind][prev_ind+1]!=-1)
            return dp[ind][prev_ind+1];
        //not Take case
        int len = 0 + rec_fn(ind+1, prev_ind, nums, dp);
        //take case
        if(prev_ind  == -1 || nums[ind] > nums[prev_ind])
            len = max(len, 1 + rec_fn(ind+1, ind, nums, dp));
        return dp[ind][prev_ind+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return rec_fn(0,-1,nums, dp);
    }
};