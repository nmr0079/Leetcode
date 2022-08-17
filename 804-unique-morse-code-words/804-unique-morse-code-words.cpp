class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> alphabets = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string,int> uniq_morse;
        for(int i = 0; i<words.size(); i++){
            string trans = "";
            for(int j =0;j < words[i].size(); j++){
                int idx = words[i][j] - 'a';
                trans += alphabets[idx];
            }
            uniq_morse[trans] = 1;
        }
        return uniq_morse.size();
    }
};