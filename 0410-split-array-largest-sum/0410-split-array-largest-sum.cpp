class Solution {
public:
    bool possible(vector<int>& nums, int k, int mid) {
        int cnt = 1;
        int sum = 0;

        for (int x : nums) {
            if (sum + x <= mid) {
                sum += x;
            } else {
                cnt++;
                sum = x;
            }
        }

        return cnt <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;

        for (int x : nums)
            high += x;

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};