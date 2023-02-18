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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()){
            int size = q.size();
            for(int i = 0;i < size;i++){
                    TreeNode* node = q.front();
                    q.pop();
                    
                    if(!node)
                        continue;
                    TreeNode* left = node->left;
                    TreeNode* right = node->right;
                
                    node->left = right;  //Inversion phase
                    node->right = left; 
                
                
                    q.push(node->left);
                    q.push(node->right);
            }
            
        }
        
      return root;  
    }
};