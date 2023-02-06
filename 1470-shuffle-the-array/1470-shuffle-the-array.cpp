class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> shuffled_array(2*n);
        int ptr1,ptr2;
        ptr1 = 0;
        ptr2 = n;
        int i = 0;
        while(ptr1 < n && ptr2 < 2*n )
        {
            shuffled_array[i] = nums[ptr1];
            shuffled_array[++i] = nums[ptr2];
            ++ptr1;
            ++ptr2;
            ++i;
        }
        return shuffled_array;
    }
};