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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int maxDep = 0;
        queue<TreeNode*> bfs;
        bfs.push(root);
        
        while(bfs.size() != 0){
             int size = bfs.size();
            for(int i = 0;i < size;i++){
                TreeNode* nodei = bfs.front();
                if(nodei->left)
                      bfs.push(nodei->left);
                if(nodei->right)
                      bfs.push(nodei->right);
                bfs.pop();
            }
            maxDep++;
        }
        
        return maxDep;
    }
};