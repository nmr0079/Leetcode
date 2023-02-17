class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n1 = nums.size();
        int left = 0, right = n1-1;
        
        while(left < right){
           int count = 0;
           int mid = left + (right - left)/2;
            
            for(int i = 0;i < n1;i++){
                if(nums[i] <= mid)
                    count++;
            }
            
            if(count <= mid)
                left = mid+1;
            else
                right = mid;
        }
        
        return left;
        
    }
};