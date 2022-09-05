/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
         if(!root)
             return result;
          queue<Node*> tree_queue;
          tree_queue.push(root);
          int qsize;
          while(!tree_queue.empty()){
              qsize = tree_queue.size();
              result.push_back({});
               while(qsize != 0){
                Node *node = tree_queue.front();
                tree_queue.pop();
                result.back().push_back(node->val);
                for(auto node_ch:node->children)
                      tree_queue.push(node_ch);
                    
                --qsize;
               }
          }
         return result;
    }
};