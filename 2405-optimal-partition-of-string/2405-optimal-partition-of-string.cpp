class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int count = 0;
        int i = 0;
        // for(int i = 0;i < n;i++){
        //     charFreq[s[i]]++;
        //     if(charFreq[s[i]] > 1){
        //         count++;
        //         charFreq[s[i]] = 1;
        //     }
        // }
        
        while(i < n){
            unordered_map<char,int> charFreq;
            while(charFreq[s[i]] == 0 && i < n){
                charFreq[s[i]]++;
                i++;
            }
            count++;
        }
        return count;
    }
};