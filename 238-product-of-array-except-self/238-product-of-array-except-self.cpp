class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answers;
        
        // //Brute Force
        // for(int i = 0;i < n;i++){
        //     int answeri = 1;
        //     for(int j = 0;j < n;j++){
        //         if(j == i)
        //             continue;
        //         answeri *= nums[j];
        //     }
        //     answers.push_back(answeri);
        // }
        
        //With Division 
        int fullprod = 1;
        int fullprodzero = 1;
        int num_zero = 0;
        for(int i = 0;i < n;i++){
            fullprod *= nums[i];
            if(nums[i] == 0)
                num_zero++;
            if(nums[i] != 0)
                fullprodzero *= nums[i];
        }
        
        for(int i = 0;i < n;i++){
            if(num_zero > 1){
                answers.push_back(0);
                continue;
            }
            else if(num_zero == 1 && nums[i] == 0)
                answers.push_back(fullprodzero);
            else
                answers.push_back(fullprod/nums[i]);
        }
        
        return answers;
    }
};