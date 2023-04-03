class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int left = 0, right = n-1;
        sort(people.begin(),people.end());
        int count = 0;
        while(left <= right){
            if(people[right] == limit){
                count++;
                right--;
            }
            else if(people[left]+people[right] > limit)
            {
                count++;
                right--;
            }
            else{
                count++;
                right--;
                left++;
            }
         
        }
        return count;
    }
};