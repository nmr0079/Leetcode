class Solution {
public:
    string frequencySort(string s) {
        string s2;
        unordered_map<char, int> charFreq; //Maps each character to it's frequency(no: of times occured)
        priority_queue<pair<int,char>> maxheap; //Maxheap w.r.t frequency
        for(char &c: s){
            charFreq[c]++;
        }
        
        for(auto it: charFreq){
            maxheap.push({it.second, it.first});            
        }
        
        while(!maxheap.empty()){
            s2 += string(maxheap.top().first, maxheap.top().second); //string(3,'c') => ccc
            maxheap.pop();
        }
        
        return s2;
    }
};