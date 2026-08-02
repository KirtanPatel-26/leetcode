class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int n = nums1.size();
        int m = nums2.size();
        
        for(int i=0;i<n;i++){
            v.push_back(nums1[i]);
        }
        for(int i=0;i<m;i++){
            v.push_back(nums2[i]);
        }
        sort(v.begin(),v.end());

        int k = v.size();

        if(k%2 == 0){
            return (v[k/2 - 1] + v[k/2])/2.0;
        }
        else{
            return v[k/2];
        }
        return 0;
    }
};