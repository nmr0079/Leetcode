class Solution {
public:
    
    vector<int> findAnagrams(string s, string p) {
         unordered_map<char, int> sh,ph;
         int n1 = s.size(), n2 = p.size();
         vector<int> indexes;
        
         for(int i = 0;i < n2;i++){
             ph[p[i]]++;
             sh[s[i]]++;
         }
        
         if(ph == sh)   
             indexes.push_back(0);
        
         int j = 0;
         for(int i = n2;i < n1;i++){
             sh[s[i]]++;
             sh[s[j]]--;
             if(sh[s[j]] == 0)
                 sh.erase(s[j]);
             j++;
             if(ph == sh)
                 indexes.push_back(j);
         }
         return indexes;
    }
};