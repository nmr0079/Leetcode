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
    int findPathSum(TreeNode* root, int& maxi){
        //base case
        if(root == NULL)
            return 0;
        
        int leftMaxSum = max(0, findPathSum(root->left, maxi));
        int rightMaxSum = max(0, findPathSum(root->right, maxi));
        int val = root->val;
        maxi = max(maxi, (leftMaxSum + rightMaxSum)+val);
        return max(leftMaxSum, rightMaxSum) + val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findPathSum(root, maxi);
        
        return maxi;
    }
};