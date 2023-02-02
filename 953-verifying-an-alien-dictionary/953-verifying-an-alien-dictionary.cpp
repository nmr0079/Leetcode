class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int now = words.size();
        unordered_map<char,int> ordermap;
        int cnt = 0;
        for(auto &c: order){
            ordermap[c] = ++cnt; 
        }
        
        for(int i = 0;i < now-1;i++){
            
            for(int j = 0;j < words[i].size();j++){
                
                if(ordermap[words[i][j]] < ordermap[words[i+1][j]]){
                     j = words[i].size();
                    continue;
                }
                
                else if(ordermap[words[i][j]] == ordermap[words[i+1][j]]){
                    continue;
                }
                
                else
                    return false;
            }
        }
        
        return true;
        
    }
};