class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        
        if(n == 1)
            return ans;
        
        string str = countAndSay(n-1);
        ans = "";
        
        int n1 = str.size();
        for(int i = 0;i < n1;i++){
            int count = 1;
            while(i < (n1-1) && str[i] == str[i+1]){
                count++;
                i++;
            }
            ans.append(to_string(count) + str[i]);
        }
        
        return ans;
        
        
    }
};