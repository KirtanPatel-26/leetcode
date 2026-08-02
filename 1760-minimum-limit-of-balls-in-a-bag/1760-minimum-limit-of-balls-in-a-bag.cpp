class Solution {
public:
    int ball(vector<int>& nums, int mid, int maxOperations){
        long long operations = 0;

        for(int x : nums){
            operations += (x-1)/mid;
        }
        if(operations > maxOperations){
            return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());

        while(low<= high){
            int mid = (low+high)/2;

            if(ball(nums, mid, maxOperations) == true){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};