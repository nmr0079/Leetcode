class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        int n1 = s.size(), n2 = t.size(), count = 0;
        
        if(n1 != n2)
            return false;
        
         for (char const &c: s) {
             map[c]++;
         }
        
         for (char const &c: t) {
             map[c]--;
         }
    
         for (char const &c: s) {
             if(map[c] == 0)
                 count++;
         }
        
        if(count == n1)
            return true;
        
        return false;
    }
};