class Solution {
public:
    deque<int> dq;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
          deque<int> dq;
          vector<int> result;
          for(int i = 0;i < nums.size();i++){
              while(!dq.empty() and dq.back() < nums[i])
                  dq.pop_back();
              dq.push_back(nums[i]);
              if(i >= k-1)
              {
                  result.push_back(dq.front());
                  if(dq.front() == nums[i - k+1])
                        dq.pop_front();
              }   
          }
          return result;
        
    }
};