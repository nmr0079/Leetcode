class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int leftmax = height[left],rightmax = height[right];
        int ans = 0,h;
        
        while(left <= right){
            if(height[left] > height[right]){
                h = height[right];
                if(h > rightmax)
                    rightmax = h;
                else
                    ans += rightmax - h;
                
                --right;
            } 
            else
            {
                h = height[left];
                if(h > leftmax)
                    leftmax = h;
                else
                    ans += leftmax - h;
                
                ++left;
            }
        }
        
        return ans;
    }
};