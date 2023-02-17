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
    vector<int> inorderArray;
    void inorderTraversal(TreeNode* root){
        //base case
        if(root == nullptr)
            return;
        
        inorderTraversal(root->left);
        inorderArray.push_back(root->val);
        inorderTraversal(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        inorderTraversal(root);
        
        for(int i = 1;i < inorderArray.size();i++){
            minDiff = min(minDiff,inorderArray[i]-inorderArray[i-1] );
        }
        return minDiff;
    }
};