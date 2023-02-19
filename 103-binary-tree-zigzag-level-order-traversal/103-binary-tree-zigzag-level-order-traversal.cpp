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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> zigTrav;
        q.push(root);
        int level = 0;
        
        while(q.size()){
            int size = q.size();
            vector<int> leveltrav;
            for(int i = 0;i < size;i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(!node)
                    continue;
                
                
                if(level%2 != 0){
                    leveltrav.insert(leveltrav.begin(),node->val);
                }
                else{
                    leveltrav.push_back(node->val);
                }
                  q.push(node->left);
                    q.push(node->right);
                
                
             }
            level++;
            if(leveltrav.size())
                  zigTrav.push_back(leveltrav);
        }
        
        return zigTrav;
    }
};