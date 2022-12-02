class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int len1 = word1.size();
        
        if(len1 != word2.length())
            return false;
        
        unordered_map<char, int> charFreq1;
        unordered_map<char, int> charFreq2;
        
        vector<int> v1;
        vector<int> v2;
        
        for (char & c : word1)
        {
            charFreq1[c]++;
        }
       
        for (char & c : word2)
        {
            charFreq2[c]++;
        }
        
        for(int i = 0;i < len1;i++){
            if(word2.find(word1[i]) != std::string::npos )
                v1.push_back(charFreq1[word1[i]]);
            else
                return false;
             if(word1.find(word2[i]) != std::string::npos )
                v2.push_back(charFreq2[word2[i]]);
            else
                return false;
        }
        sort(begin(v1), end(v1));
        sort(begin(v2), end(v2));
        
        if(v1 == v2)
            return true;
        else
           return false;
    }
};