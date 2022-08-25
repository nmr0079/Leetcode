class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ransom_size = ransomNote.size();
        int mag_size = magazine.size();
        unordered_map<char, int> map1;
         unordered_map<char, int> map2;
        
        for(int i = 0;i < ransom_size;i++)
            map1[ransomNote[i]] += 1;
        
         
        for(int j = 0;j < mag_size;j++)
            map2[magazine[j]] += 1;
        
        for(int k = 0;k < ransom_size;k++){
            if(map1[ransomNote[k]] > map2[ransomNote[k]])
                return false;
        }
        return true;
        
    }
};