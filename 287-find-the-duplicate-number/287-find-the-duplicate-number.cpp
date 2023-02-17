class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n1 = nums.size();
        int dup;
        
        for(int i = 0;i < n1;i++){
            int index = abs(nums[i]);
            
            if(nums[index] < 0)
            {
                dup = index;
                break;
            }
            
            nums[index] *= -1;
        }
        
        return dup;
        
    }
};