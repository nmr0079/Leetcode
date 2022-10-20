class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int left = 0, right = n -1,ptr;
        
        while(left < right){
            int mid = left + (right - left)/2;
            
            if(mid % 2 == 0)
                ptr = mid+1;
            else
                ptr = mid-1;
            
            if(nums[ptr] == nums[mid]) // implies that the LHS satisfies the condition
                left = mid+1;
            else
                right = mid;
            }
        return nums[left];
    }
};