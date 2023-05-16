class Solution {
public:
    bool posToDiv(int mid, vector<int>& nums, int k){
        int subarrays = 1;
        int sum = 0;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            if(sum > mid){
                sum = nums[i];
                subarrays++;
            }
            
            if(subarrays > k)
                return false;
        }
        
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, max_num = INT_MIN;
        for(int i = 0;i < n;i++){
            sum += nums[i];
            max_num = max(max_num, nums[i]);
        }
        
        int left = max_num, right = sum;
        while(left < right){
            int mid = left + (right - left)/2;
            if(posToDiv(mid, nums, k))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};