class Solution {
public:
    void dfs(int i,vector<vector<int>>& adj,vector<vector<int>>& back,vector<bool>& visited,int& min_reorders){
        visited[i] = true;
        for(auto& nbhr: adj[i]){
            if(!visited[nbhr]){
                min_reorders++;
                dfs(nbhr,adj,back,visited,min_reorders);
            }
        }
        for(auto& nbhr: back[i]){
            if(!visited[nbhr]){
                dfs(nbhr,adj,back,visited,min_reorders);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<vector<int>> back(n);
        int n1 = connections.size();
        
        for(auto& connection: connections){
            adj[connection[0]].push_back(connection[1]);
            back[connection[1]].push_back(connection[0]);
        }
        
        vector<bool> visited(n);
        int min_reorders = 0;
        visited[0] = true;
        
        for(int i = 0;i < n;i++){
            if(!visited[i] || i==0){
                 dfs(i,adj,back,visited,min_reorders);
            }
        }
        return min_reorders;
    }
};