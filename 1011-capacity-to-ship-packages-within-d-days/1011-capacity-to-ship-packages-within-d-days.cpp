class Solution {
public:
    bool isFeasible(int capacity, vector<int>& weights, int days){
        int daysPassed = 1;
        int weightNow = 0;
        for(int i = 0;i < weights.size();i++){
            weightNow += weights[i];
            if(weightNow > capacity){
                weightNow = weights[i];
                daysPassed++;
            }
            if(daysPassed > days)
                return false;
        }
        
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sumWeight = 0, max_weight = INT_MIN;
        for(int i = 0;i < n;i++){
            sumWeight += weights[i];
            max_weight = max(max_weight, weights[i]);
        }
        
        int left = max_weight, right = sumWeight;
        while(left < right){
            int mid = left + (right - left)/2;
            if(isFeasible(mid, weights, days))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};