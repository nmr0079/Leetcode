class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> answers;
        vector<vector<int> > adj(numCourses, vector<int>(numCourses));
        
        for(int i = 0;i < prerequisites.size();i++){
            adj[prerequisites[i][0]][prerequisites[i][1]] = 1;
        }
        
        for(int k = 0;k < numCourses;k++)
            for(int i = 0;i < numCourses;i++)
                for(int j = 0;j < numCourses;j++)
                    adj[i][j] = adj[i][j] or (adj[i][k] and adj[k][j]);
        
        for(int i = 0;i < queries.size();i++){
            if(adj[queries[i][0]][queries[i][1]] == 1)
                answers.push_back(true);
            else
                answers.push_back(false);
        }
        return answers;
        
    }
};