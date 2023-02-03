class Solution {
public:
    void recursivefn(int idx,vector<int>& candidates,int target,vector<vector<int>>& output,vector<int>& ds){
        
        if(idx == candidates.size()){
            if(target == 0){
                output.push_back(ds);
            }
            return;
        }
        
        if(candidates[idx] <= target){  //picks up the element at idxth index
            ds.push_back(candidates[idx]);
            recursivefn(idx, candidates, target - candidates[idx],output,ds);
            ds.pop_back();  //backtracking
        }
        
        recursivefn(idx+1, candidates, target, output, ds);
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;  //For the list of all possible unique combinations
        vector<int> ds; //For the individual combinations
        recursivefn(0,candidates,target,output,ds);
        return output;
    }
};