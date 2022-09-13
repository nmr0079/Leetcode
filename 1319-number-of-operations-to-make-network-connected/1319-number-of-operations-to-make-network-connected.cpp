class Solution {
public:
     vector<int> parent;
     vector<int> size;
    
    void swap(int &x,int &y){
        int temp = x;
        x = y;
        y = temp;
    }
    
     void make_sets(int n) {
        for(int i = 0;i < n;i++){
            parent.push_back(i);
            size.push_back(1);
        }
     }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
         }
    }
    
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int conn_size = connections.size();
        if(conn_size < (n-1))
            return -1;
        
        make_sets(n);
        
        for(int i = 0;i < conn_size;i++){
           union_sets(connections[i][0], connections[i][1]);
        }
        
        int cluster_count = 0;
        for(int i = 0;i < n;i++)
            if(parent[i] == i)
                cluster_count++;
        
        return cluster_count - 1;
        
    }
};