class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        
        while(left < right){
          if(s[left] != s[right])
                return false;
            else{
                left++;
                right--;
            }
        }
        return true;
    }
    
    void rec_partition(string s, int start, vector<string> &valid_part, vector<vector<string>> &out){
        //base case
        if(start == s.size()){
            out.push_back(valid_part);
            return;
        }
        
        for(int i = start;i < s.size();i++){
            if(isPalindrome(s.substr(start,i-start+1))){
                valid_part.push_back(s.substr(start,i-start+1));
                rec_partition(s,i+1,valid_part,out);
                valid_part.pop_back();  //Backtrack part
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> out;
        vector<string> valid_part;
        rec_partition(s,0,valid_part,out);
        return out;
    }
};