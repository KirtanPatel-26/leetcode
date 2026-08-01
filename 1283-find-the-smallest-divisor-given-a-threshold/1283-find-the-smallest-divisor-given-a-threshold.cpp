class Solution {
public:
    int divide(vector<int>& nums, int divisor, int threshold){
        int n = nums.size();
        int sum = 0;

        for(int i=0;i<n;i++){
            sum += (nums[i] + divisor - 1) / divisor;
        }
        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = (low+high)/2;

            if(divide(nums,mid,threshold) == true){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};