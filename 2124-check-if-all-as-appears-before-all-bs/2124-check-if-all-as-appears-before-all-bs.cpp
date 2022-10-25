class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        
        if(n == 1 && s[0] == 'a')
            return true;
        int count = 0;
        
        for(int i = 0;i < n-1;i++){
            if(s[i] > s[i+1])
                count++;
        }
        
        if(count > 0)
            return false;
        else
            return true;
    }
};