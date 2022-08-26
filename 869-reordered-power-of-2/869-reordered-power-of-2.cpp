class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string number = to_string(n);
        sort(number.begin(), number.end());
        for(int i = 0; i < 30; i++){
            string pow_two = to_string(1 << i);
            sort(pow_two.begin(), pow_two.end());
            if(number == pow_two)
                return true;
        }
        return false;
        
    }
};