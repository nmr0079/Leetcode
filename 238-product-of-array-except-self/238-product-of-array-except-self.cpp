class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answers(n,1);
        
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
        
//         //With Division Not recommended as the Q suggests not to use division
//         int fullprod = 1;
//         int fullprodzero = 1;
//         int num_zero = 0;
//         for(int i = 0;i < n;i++){
//             fullprod *= nums[i];
//             if(nums[i] == 0)
//                 num_zero++;
//             if(nums[i] != 0)
//                 fullprodzero *= nums[i];
//         }
        
//         for(int i = 0;i < n;i++){
//             if(num_zero > 1){
//                 answers.push_back(0);
//                 continue;
//             }
//             else if(num_zero == 1 && nums[i] == 0)
//                 answers.push_back(fullprodzero);
//             else
//                 answers.push_back(fullprod/nums[i]);
//         }
        //Another way,but gives a TLE at 19th test case
        //vector<int> prefixans;
       // vector<int> suffixans;
//         int ans = 1;
//         prefixans.push_back(1);
//         for(int i = 1;i < n;i++){
//             ans *= nums[i-1];
//             prefixans.push_back(ans);
//         }
        
//         suffixans.push_back(1);
//         ans = 1;
//         for(int i = n-2;i>=0;i--){
//             ans *= nums[i+1];
//             suffixans.insert(suffixans.begin(), ans);
//         }
        
//         for(int i = 0;i < n;i++){
//             answers.push_back(prefixans[i]*suffixans[i]);
//         }
       
        //Now, using the above way,but in O(1) auxillary space
       int presufprod = 1;
       for(int i = 0;i < n;i++){
           answers[i] *= presufprod;
           presufprod *= nums[i];
       }
       
        presufprod = 1;
        for(int i = n-1;i >= 0;i--){
            answers[i] *= presufprod;
            presufprod *= nums[i];
        }
        
        return answers;
    }
};