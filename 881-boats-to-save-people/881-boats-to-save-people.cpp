class Solution {
public:
    bool enoughBoats(int mid,vector<int>& people, int limit){
        int n = people.size();
        int left = 0, right = n-1;
        while(left <= right){
            if(people[right] == limit){
                mid--;
                right--;
            }
            else if(people[left]+people[right] > limit)
            {
                mid--;
                right--;
            }
            else{
                mid--;
                right--;
                left++;
            }
         
        }
        if(mid >= 0)
            return true;
        return false;
    }
    
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int left = 1, right = n;
        sort(people.begin(),people.end());
        while(left < right){
            int mid = left + (right - left)/2;
            if(enoughBoats(mid,people,limit))
                right = mid;
            else
                left = mid+1;
        }
        return right;
    }
};