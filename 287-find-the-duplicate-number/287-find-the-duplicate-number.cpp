class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare = nums[0];
        int tortoise = nums[0];
        
        //Phase I : Finding the intersection point 
        do{
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }while(hare != tortoise);
        
        //Phase II : Next intersection point will give the node where cycle occurs
        tortoise = nums[0];
        while(tortoise != hare){
            hare = nums[hare]; //hare is moving at a speed of tortoise
            tortoise = nums[tortoise];
        }
        
        return hare;
        
    }
};