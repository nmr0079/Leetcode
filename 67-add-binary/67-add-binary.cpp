class Solution {
public:
    string addBinary(string a, string b) {
       int n1 = a.size(), n2 = b.size();
        string ans;
        if(n1 < n2){
            for(int i = 0;i < n2-n1;i++)
                a = '0' + a;
            n1 = n2;
        }
        else if(n2 < n1){
            for(int i = 0;i < n1-n2;i++)
                b = '0'+b;
            n2 = n1;
        }
        
        int carry = 0;
        for(int i = n1-1;i >= 0;i--){
            int fb = a.at(i) - '0';
            int sb = b.at(i) - '0';
            
            int sum = (fb ^ sb ^ carry) + '0';
            ans = char(sum) + ans;
            carry = (fb & sb) | (fb & carry) | (sb & carry);
        }
        
        if(carry)
            ans = '1' +ans;
        
        return ans;
    }
};