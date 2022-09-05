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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;
        queue<TreeNode*> tree_queue;
        tree_queue.push(root);
        int qsize;
        while(!tree_queue.empty()){
            qsize = tree_queue.size();
            vector<int> curr_level;
            while(qsize!= 0){
                TreeNode* node = tree_queue.front();
                tree_queue.pop();
                curr_level.push_back(node->val);
                if (node->left != NULL)
                    tree_queue.push(node->left);
                if (node->right != NULL)
                    tree_queue.push(node->right);
                --qsize;
            }
            result.push_back(curr_level);
        }
        return result;
    }
};