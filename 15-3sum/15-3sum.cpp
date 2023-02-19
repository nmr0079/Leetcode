class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> threeSum;
        
        for(int i = 0;i <n-2;i++){
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){ //For avoiding calc for same nums[i]
            int lo = i+1;
            int hi = n-1;

            while(lo < hi){
                if(nums[lo]+nums[hi] == -(nums[i])){
                     vector<int> triplets;
                    triplets.push_back(nums[i]);
                    triplets.push_back(nums[lo]);
                    triplets.push_back(nums[hi]);
                    threeSum.push_back(triplets);
                    
                    
                    while(lo < hi && nums[lo] == nums[lo+1]){lo++;}
                    while(lo < hi && nums[hi] == nums[hi-1]){hi--;}
                    
                    lo++;
                    hi--;
                }
                else if(nums[lo]+nums[hi] < -(nums[i]))
                    lo++;
                else
                    hi--;
            }
            
        }
        }
        
        return threeSum;
    }
};