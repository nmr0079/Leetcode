class Solution {
public:
    // void dfs(int i, vector<int>& visited, unordered_map<int, vector<int>>& adjList){
    //     visited[i] = 1;
    //     for(auto it: adjList[i]){
    //         if(!visited[it])
    //             dfs(it, visited, adjList);
    //     }
    // }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int, int> incomEdges(n);
        // vector<int> visited(n, 0);
        vector<int> renodes;
        int no_edges = edges.size();
        
        for(int i = 0;i < no_edges;i++){
            incomEdges[edges[i][1]]++;
        }
        
        for(int i = 0;i < n;i++){
           if(incomEdges[i] == 0)
               renodes.push_back(i);
        }
        return renodes;
    }
};