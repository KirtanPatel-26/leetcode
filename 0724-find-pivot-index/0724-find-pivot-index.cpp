class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0;
        int sum2 = 0;

        for (int i = 0; i < n; i++) {
            sum2 += nums[i];
        }

        for (int i = 0; i < n; i++) {
            sum2 -= nums[i];    

            if (sum1 == sum2) {
                return i;
            }

            sum1 += nums[i];
        }

        return -1;
    }
};