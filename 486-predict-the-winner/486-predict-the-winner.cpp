class Solution {
public:
    bool helper(vector<int>& nums,bool turn,int p1_score,int p2_score,int i,int j){
        if(i > j){
            return p1_score >= p2_score;
        }
        if(turn){
            return helper(nums,false,p1_score+nums[i],p2_score,i+1,j) || helper(nums,false,p1_score+nums[j],p2_score,i,j-1);
        }
        else{
            return helper(nums,true,p1_score,p2_score+nums[i],i+1,j) && helper(nums,true,p1_score,p2_score+nums[j],i,j-1);
        }
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        return helper(nums,true,0,0,0,nums.size()-1);
    }
};
