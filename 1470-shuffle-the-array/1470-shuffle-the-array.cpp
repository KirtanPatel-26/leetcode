class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v;
        int first = 0;
        int second = n;

        for (int i = 0; i < 2 * n; i++) {
            if (i % 2 == 0)
                v.push_back(nums[first++]);
            else
                v.push_back(nums[second++]);
        }

        return v;
    }
};