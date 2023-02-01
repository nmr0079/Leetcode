class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int prefixsum[n+1];
        vector<int> runningsum;
        prefixsum[0] = nums[0];
        runningsum.push_back(prefixsum[0]);
        for(int i = 1;i < n;i++){
            prefixsum[i] = prefixsum[i-1] + nums[i];
            runningsum.push_back(prefixsum[i]);
        }
        
        return runningsum;
    }
};