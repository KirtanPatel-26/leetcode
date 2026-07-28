class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int> inc = nums;
        vector<int> dec = nums;

        sort(inc.begin(),inc.end());

        sort(dec.begin(),dec.end());
        reverse(dec.begin(),dec.end());

        return nums == inc || nums == dec;
    }
};