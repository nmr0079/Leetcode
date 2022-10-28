class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> anagrams;
 
        
        for(int i = 0;i < n;i++){
            string str1 = strs[i]; //store the string from the list before sorting it
            sort(strs[i].begin(),strs[i].end()); //sort it
            anagrams[strs[i]].push_back(str1);
            
        }
        
        for(auto i = anagrams.begin();i != anagrams.end(); i++)
            ans.push_back(i->second);
        
    return ans;
    }
};