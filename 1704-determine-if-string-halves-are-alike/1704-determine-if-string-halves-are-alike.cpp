class Solution {
public:
    bool halvesAreAlike(string s) {
        int acount = 0,bcount = 0;
        int len = s.size();
        
        for(int i = 0;i < len/2;i++){
           if(s[i] == 'a' || s[i] == 'e' ||  s[i] == 'i' ||  s[i] == 'o' ||  s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                acount++;
        }
        
         for(int i = len/2;i < len;i++){
            if(s[i] == 'a' || s[i] == 'e' ||  s[i] == 'i' ||  s[i] == 'o' ||  s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                bcount++;
        }
        
        if(acount == bcount)
            return true;
        return false;
        
    }
};