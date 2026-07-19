class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
        int digit = 0;
            while(nums[i] != 0){
                nums[i] = nums[i]/10;
                digit++;
            }
            if(digit%2 == 0){
                cnt++;
            }
        }
        return cnt;
    }
};