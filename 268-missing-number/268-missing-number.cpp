class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size() == 1){
            if(nums[0] == 0)
                return 1;
            else
                return 0;
        }
      
        
        
        sort(nums.begin(), nums.end());
           if(nums[nums.size()-1] == nums.size() - 1)
            return nums.size();
        int left = 0, right = nums.size() - 1;
        
        while(left < right)
        {
            int mid = left + (right - left)/2;
             if(nums[mid] == mid){
                left=mid+1;
            }
            else
            {
                right = mid;
            }
            
        }
        return left;
    }
};