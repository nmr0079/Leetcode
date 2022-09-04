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
    void indexing(TreeNode* t_node, int x, int y, map<int, multiset<pair<int, int>>>& map){
        if(t_node == nullptr)
            return;
        map[y].insert({x, t_node->val});
        indexing(t_node->left, x+1,y-1, map);
        indexing(t_node->right, x+1, y+1, map);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, multiset<pair<int, int>>> map;
        vector<vector<int>> ans;
        indexing(root, 0, 0, map);
        for(auto& [y, pair]: map){
            ans.push_back({});
            for(auto& [x, val]:pair)
                ans.back().push_back(val);
                
        }
        return ans;
    }
};