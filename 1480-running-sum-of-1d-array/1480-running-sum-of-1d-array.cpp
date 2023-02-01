class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int prefixsum;
        prefixsum = nums[0];
        for(int i = 1;i < n;i++){
            int currsum = prefixsum + nums[i];
            nums[i] = currsum;
            prefixsum = currsum;
        }
        
        return nums;
    }
};