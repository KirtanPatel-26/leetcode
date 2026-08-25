class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sum = 0;

        for(int i=0;i<n && k>0;i++){
            if(nums[i] < 0){
                nums[i] = -nums[i];
                k--;
            }
        }

        if(k%2 == 1){
            int mn = 0;

            for(int i=1;i<n;i++){
                if(nums[i] < nums[mn]){
                    mn = i;
                }
            }
            nums[mn] = -nums[mn];
        }

        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        return sum;
    }
};