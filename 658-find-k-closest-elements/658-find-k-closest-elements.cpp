class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0, right = n - 1;
        while (right - left + 1 > k)
            if (abs(arr[right] - x) >= abs(arr[left] - x))
                right--;
            else
                left++;
        vector<int> res(arr.begin() + left, arr.begin() + right + 1);
        return res;
    
    }
};