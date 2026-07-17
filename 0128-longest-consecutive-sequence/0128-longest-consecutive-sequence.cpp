class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;

        sort(nums.begin(), nums.end());

        int longest = nums[0];
        int cnt = 1;
        int ans = 1;

        for (int i = 1; i < n; i++){
            if (nums[i] == longest + 1){
                cnt++;
                longest = nums[i];
            }
            else if (nums[i] != longest){
                cnt = 1;
                longest = nums[i];
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};