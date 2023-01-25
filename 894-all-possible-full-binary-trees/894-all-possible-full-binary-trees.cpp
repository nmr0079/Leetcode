/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    static constexpr int maxN = 20+1;
    array<vector<TreeNode*>, maxN> c;
    
    vector<TreeNode*> allPossibleFBT(int n) {
        return helper(n);
    }
    vector<TreeNode*>& helper(int n) {
        if(c[n].size() > 0){
            return c[n];
        }
        vector<TreeNode*>& output = c[n];
        if(n%2 == 0){
            output = {};      //n must be odd to get a full binary tree,for even,no possible FBT
        }
        
        if(n == 1)
        {
            output = {new TreeNode(0)};
        }
       
        
        //Recursive solution
        for(int i = 1;i < n;i+= 2){ // i+=2 for odd no: of nodes 
            for(const auto& l: helper(i))
                for(const auto& r: helper(n-i-1)){
                    auto treeroot = new TreeNode(0);
                    treeroot->left = l;
                    treeroot->right = r;
                    output.push_back(treeroot);
                }
        }
        
        
        return output;
        
    }
};