class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int prefixsum;
        vector<int> runningsum;
        prefixsum = nums[0];
        runningsum.push_back(prefixsum);
        for(int i = 1;i < n;i++){
            int currsum = prefixsum + nums[i];
            runningsum.push_back(currsum);
            prefixsum = currsum;
        }
        
        return runningsum;
    }
};