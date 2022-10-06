class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if(m >= n){
            for(int i = 0;i < n;i++)
                nums1.push_back(nums2[i]);
        
        
        sort(nums1.begin(), nums1.end());
        
        int mn = nums1.size();
        
        if(mn % 2)
            return double(nums1[mn/2]);
        else
            return (nums1[mn/2] + nums1[mn/2 - 1])/2.000;
    }
    else{
    
    for(int i = 0;i < m;i++)
                nums2.push_back(nums1[i]);
        
        
        sort(nums2.begin(), nums2.end());
        
        int mn = nums2.size();
        
        if(mn % 2)
            return double(nums2[mn/2]);
        else
            return (nums2[mn/2] + nums2[mn/2 - 1])/2.000;
    }
    }
};