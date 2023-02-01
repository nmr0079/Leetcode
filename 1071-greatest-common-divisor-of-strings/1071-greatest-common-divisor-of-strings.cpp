class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1){ //GCD for str1 and str2 exists only if str1+str2 = str2+str1
            return "";                 //if the above is true => there is a substring which is repeating
        }                              //in either both or the larger string
        
        return str1.substr(0, gcd(str1.length(), str2.length()));
    }
};