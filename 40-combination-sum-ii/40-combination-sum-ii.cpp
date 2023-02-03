class Solution {
public:
    void findcomb2(int idx,int target,vector<int>& a,vector<vector<int>>& out,vector<int>& ds){
        //Base condition
        if(target == 0){
            out.push_back(ds);
            return;
        }
        
        for(int i = idx;i < a.size();i++){  //We can pick any index starting from idx to n-1
            if(i > idx && a[i] == a[i-1])  //for duplicate elimination
                continue;
            
            if(a[i] > target)  //if this is true, then for all i = i+1 -> n-1 also,this is true
                break;         //since candidates were sorted before being passed
            
            ds.push_back(a[i]);
            findcomb2(i+1, target - a[i], a, out, ds);
            ds.pop_back();   //backtracking step
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> output;
        vector<int> ds;
        findcomb2(0, target, candidates,output,ds);
        return output;
    }
};