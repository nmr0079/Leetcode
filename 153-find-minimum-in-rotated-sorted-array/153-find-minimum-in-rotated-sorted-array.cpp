class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        if(n ==1)
            return nums[0];
        
        int left = 0, right = n-1;
        
        
        while(left < right){
            int mid = left + (right - left)/2;
            
            if(nums[left] < nums[right])
                return nums[left];
            else if(nums[mid] > nums[right])
                left = mid+1;
            else
                right = mid;
            
            
        }
        return nums[left];
    }
};