class Solution {
public:
    //Solution with TC - O(n) and SC - O(n)
//     vector<int> shuffle(vector<int>& nums, int n) {
//         vector<int> shuffled_array(2*n);
//         int ptr1,ptr2;
//         ptr1 = 0;
//         ptr2 = n;
//         int i = 0;
//         while(ptr1 < n && ptr2 < 2*n )
//         {
//             shuffled_array[i] = nums[ptr1];
//             shuffled_array[++i] = nums[ptr2];
//             ++ptr1;
//             ++ptr2;
//             ++i;
//         }
//         return shuffled_array;
//     }
    
      //A solution with TC - O(n) and SC - O(1)
      vector<int> shuffle(vector<int>& nums, int n) {
          //store both the number pairs to the right side of the array
          for(int i = n;i < nums.size();i++){
              nums[i] = (nums[i] << 10) + nums[i - n]; //The max of two no: will be 1000(from the constraint)
                                                       //take a number greater than the max,here 1024 (2^10)
          }
          
          int idx = 0;
          //Now retrieve the numbers and place them on the right index
          for(int i = n;i < nums.size();i++,idx+=2){
              nums[idx] = nums[i] & 1023;  //== nums[i] % 1024 (remainder)
              nums[idx+1] = nums[i] >> 10; //== nums[i]/1024 (quotient)
          }
          return nums;
      }
};