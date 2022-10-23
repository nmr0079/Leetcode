class Solution {
public:
    int mod = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        
        if(n == 1 && (nums[0]+nums[0]) <= target)
            return 1;
        
        sort(nums.begin(), nums.end());
        
        int ptr1 = 0,ptr2 = n-1;
        int count = 0;
        vector<int> pows(n, 1);
        
        for(int i = 1;i < n;i++)
            pows[i] = pows[i-1]*2%mod;
        
        while(ptr1 <= ptr2){
            if(nums[ptr1]+nums[ptr2] > target)
                ptr2--;
            else{
                count += pows[ptr2 - ptr1];
                count = count%mod;
                   ptr1++;
            }
        }
        return count;
        
    }
};