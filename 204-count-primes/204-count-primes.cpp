class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> sieve(n+1, true);
        sieve[0] = false;
        sieve[1] = false;
        
        for(int i = 2;i*i <= n;i++){
            if(sieve[i] == true){
                for(int j = i*i;j <= n;j+=i)
                    sieve[j] = false;
            }
        }
        
        for(int i = 2;i < n;i++){
            if(sieve[i] == true)
                count++;
        }
        return count;
    }
};