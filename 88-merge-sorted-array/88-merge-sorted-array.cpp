class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        while(i < m && j < n)
        {
            if(nums1[i] <= nums2[j])
                ++i;
            else
            {
                swap(nums1[i],nums2[j]);
                ++j;
            }
        }
        for(int i = m;i < (m+n);i++){
            nums1[i] = nums2[i-m];
        }
        sort(nums1.begin(),nums1.end());
    }
};