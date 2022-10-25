class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return true;
        
        int brkpt = 0;
        
        for(int i = 0;i < n;i++)
            if(nums[i] > nums[(i+1)%n])
                brkpt++;
        
        if(brkpt <= 1)   //if it is sorted and rotated, then brkpt = 1, if it's sorted, then = 0
            return true;
        else
            return false;
        
    }
};