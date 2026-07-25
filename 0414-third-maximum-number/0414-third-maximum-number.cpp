class Solution {
public:
    int thirdMax(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        if (n < 3)
            return nums[n - 1];

        vector<int> v;
        v.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                v.push_back(nums[i]);
            }
        }

        if (v.size() >= 3)
            return v[v.size() - 3];
        else
            return v.back();
    }
};