class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        vector<int> karray;
        
        
        
        while(k > 0){
            karray.insert(karray.begin(),k%10);
            k=k/10;
        }
        
        int ksize = karray.size();
        
        if(n > ksize){
            while(ksize < n){
                karray.insert(karray.begin(),0);
                ksize++;
            }
        }
        else if(n < ksize){
            while(n < ksize){
                num.insert(num.begin(),0);
                n++;
            }
        }
        
        int carry = 0;
        for(int i = n-1;i>=0;i--){
            int c = num[i]+karray[i]+carry;
            if(c > 9){
                num[i] = c%10;
                carry = 1;
            }
            else{
                num[i] = c;
                carry = 0;
            }
        }
        
        if(carry)
            num.insert(num.begin(),carry);
        
        return num;
    }
};