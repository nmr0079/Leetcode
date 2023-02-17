class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> dup;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            int index = abs(nums[i]);
            
            if(nums[index-1] < 0)
                dup.push_back(index);
            
            nums[index-1] *= -1;
        }
        
        return dup;
    }
};