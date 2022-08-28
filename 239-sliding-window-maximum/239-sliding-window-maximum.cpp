class Solution {
public:
    deque<int> dq;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
          deque<int> dq;
          vector<int> result;
          for(int i = 0;i < nums.size();i++){
              while(!dq.empty() and nums[dq.back()] < nums[i])
                  dq.pop_back();
              dq.push_back(i);
              if(i >= k-1)
              {
                  result.push_back(nums[dq.front()]);
                  if(dq.front() == i - k+1)
                        dq.pop_front();
              }   
          }
          return result;
        
    }
};