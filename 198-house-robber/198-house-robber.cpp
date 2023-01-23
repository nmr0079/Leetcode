class Solution {
public:
    //Recursive Solution
    /*int recur_fn(vector<int>& nums,int idx){
        if(idx>=nums.size()){
            return 0;
        }
        
        return max(nums[idx]+recur_fn(nums,idx+2), recur_fn(nums,idx+1));
    }*/
    
   //Memoized solution
    /*int memoized(vector<int>&nums, vector<int>&dp, int idx){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        return dp[idx] = max(memoized(nums,dp,idx+2)+nums[idx], memoized(nums,dp,idx+1));
    }*/
    
    
    int rob(vector<int>& nums) {
        //Recursive soln
        //return recur_fn(nums, 0);
        
        //Memoized solution
       /* vector<int> dp(nums.size()+1, -1);
        return memoized(nums,dp,0);*/
        
        //DP solution
      /*  vector<int> dp(nums.size());
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        
        for(int i = 2;i < n;i++){
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];*/
        //DP + O(1) solution
          int n = nums.size();
          if(n == 1){
              return nums[0];
          }
        
        int two_hs_bf = nums[0], one_hs_bf = max(nums[1],nums[0]);
        int curr_hs = one_hs_bf;
        for(int i = 2;i < n;i++){
            curr_hs = max(two_hs_bf+nums[i], one_hs_bf);
            two_hs_bf = one_hs_bf;
            one_hs_bf = curr_hs;
        }
        
        return curr_hs;
    }
};