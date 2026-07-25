class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int largest = INT_MIN;
        int seclargest = INT_MIN;
        int largestIndex = -1, secondLargestIndex = -1;

        for(int i=0;i<n;i++){
            if(nums[i]>largest){
                seclargest = largest;
                secondLargestIndex = largestIndex;

                largest = nums[i];
                largestIndex = i;
            }
            else if (nums[i] > seclargest && nums[i] != largest) {
            seclargest = nums[i];
            secondLargestIndex = i;

        }
        }
        if(largest >= 2*seclargest){
            return largestIndex;
        }
        else{
            return -1;
        }
    }
};