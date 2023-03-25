class Disjoint_Set {
    vector<int> rank,parent;  //two arrays ro be managed
    
    public:
        Disjoint_Set(int n){
            rank.resize(n+1,0);  //n+1 as it will work for both 1 indexed and 0-indexed
                                 //initially everyone's rank will be 0
            parent.resize(n+1);
            for(int i = 0;i <= n;i++)
                parent[i] = i;           //initially every node will be a single component
        }
    
        int findParent(int node){
            if(node == parent[node])
                return node;
            
            return parent[node] = findParent(parent[node]);  //path compression step
        }
    
       void unionByRank(int u,int v){
           int ultp_u = findParent(u);
           int ultp_v = findParent(v);
           
           if(ultp_u == ultp_v)
               return;
           
           if(rank[ultp_u] < rank[ultp_v]){
               parent[ultp_u] = ultp_v;   //rank of ultp_v doesn't change as ultp_u has lesser rank 
           }
           
           else if(rank[ultp_v] < rank[ultp_u]){
               parent[ultp_v] = ultp_u;
           }
           
           else{
               parent[ultp_v] = ultp_u;
               rank[ultp_u]++;
           }
       }
    
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        Disjoint_Set ds(n);
        int n_edges = edges.size();
        
        for(int i = 0;i < n_edges;i++){
            ds.unionByRank(edges[i][0],edges[i][1]);
        }
        unordered_map<int,int> nodesConnected;
        for(int i = 0;i < n;i++){
            nodesConnected[ds.findParent(i)]++;
        }
        
        long long remaining_nodes = n;
        long long paircount = 0;
        
        for(auto& ultparent: nodesConnected){
            int no_nodesConnected = ultparent.second;
            paircount += no_nodesConnected * (remaining_nodes - no_nodesConnected);
            remaining_nodes -= no_nodesConnected;
        }
        return paircount;
    }
};