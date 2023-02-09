class Solution {
public:
    void build_set(vector<int>& nums,int start,vector<int>& set,vector<vector<int>>& pset){
        //base case
        if(start == nums.size()){
            pset.push_back(set);
            return;
        }
        
        for(int i = start;i < nums.size();i++){
            set.push_back(nums[i]);
            build_set(nums,i+1,set,pset);
            set.pop_back();
        }
        pset.push_back(set);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> pset;
        vector<int> set;
        build_set(nums,0,set,pset);
        return pset;
    }
};