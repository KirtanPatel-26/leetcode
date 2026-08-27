class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();
        int temp;
        int count = 0;

        for(int i=0;i<n;i++){
            while(nums[i] > 0){
                temp = nums[i] % 10;
                if(temp == digit){
                    count++;
                }
                nums[i] = nums[i]/10;
            }
        }
        return count;
    }
};