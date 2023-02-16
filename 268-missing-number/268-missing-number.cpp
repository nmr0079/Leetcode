class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int miss_no = nums.size();
        //Logic : here, we are XORing all 0 - n numbers with all the array elements
        //So, all the numbers present in the array will see each other and make the result 0;
        //Only the missing number won't see itself in the array and will get XORed with 0 instead
        //since n ?^ 0 = n,we get the missing number
        for(int i = 0;i < nums.size();i++){  
            miss_no ^= nums[i];
            miss_no ^= i;
        }
        
        return miss_no;
    }
};