class Solution {
public:
    int dfs(int node,vector<vector<int>>& adj,vector<bool>& visited){
        visited[node] = true;
        int count = 1;
        
        for(auto& nbhr: adj[node]){
            if(!visited[nbhr]){
                count += dfs(nbhr,adj,visited);
            }
        }
        
        return count;  //For returning the number of nodes in a connected component
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        //adjacency list formation
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n);
        long long pair_count = 0;
        long long remaining_nodes = n;
        
        for(int i = 0;i < n;i++){
            if(!visited[i]){
               int count_nodes = dfs(i,adj,visited);
               pair_count += count_nodes*(remaining_nodes - count_nodes);
               remaining_nodes -= count_nodes;
            }
        }
        
        return pair_count;
    }
};