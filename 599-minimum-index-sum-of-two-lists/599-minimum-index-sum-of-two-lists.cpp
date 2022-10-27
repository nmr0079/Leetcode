class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, vector<int>> idx_map;
        int min = INT_MAX;
        vector<string> ans;
        for(int i = 0;i < list1.size();i++){
            idx_map[list1[i]].push_back(i);
        }
        
          for(int i = 0;i < list2.size();i++){
            idx_map[list2[i]].push_back(i);
              if(idx_map[list2[i]].size() == 2)
              {
                  int sum = idx_map[list2[i]][0] + idx_map[list2[i]][1];
                  if(min > sum){
                      min = sum;
                      //if(ans.size() != 0)
                          ans.clear();
                       ans.push_back(list2[i]);
                  }
                  else if(min == sum)
                      ans.push_back(list2[i]);
                  
                 
              }
        }
        
        return ans;
        
        
    }
};