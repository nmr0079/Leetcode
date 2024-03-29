class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        int pos = -1, mid;
        
        while(left <= right){
            mid = (left+right)/2;
    
            if(nums[mid] == target)
                return mid;
        
            else if (nums[left] <= nums[mid]){
                if(target < nums[mid] && target >= nums[left])
                    right = mid-1;
                else
                    left = mid+1;
            }
        
            else{
                if(target > nums[mid] && target <= nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        return pos;
    }
};