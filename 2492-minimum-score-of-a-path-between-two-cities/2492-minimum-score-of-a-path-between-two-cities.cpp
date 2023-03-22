class Solution {
public:
    int bfs(int& n, vector<vector<pair<int,int>>>& adj){
        vector<bool> visited(n+1);
        int score = INT_MAX;
        queue<int> q;
        
        q.push(1);
        visited[1] = true;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto& edge: adj[node]){
                score = min(score,edge.second);
                if(!visited[edge.first]){
                    visited[edge.first] = true;
                    q.push(edge.first);
                }
            }
        }
        return score;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        
        for(auto& road : roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        return bfs(n,adj);
    }
};