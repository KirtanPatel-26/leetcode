class Solution {
public:
    int capacity(vector<int>& weights, int day, int days){
        int n = weights.size();
        int sum = 0;
        int cnt = 1;

        for(int i=0;i<n;i++){
            if(sum+weights[i] <= day){
                sum += weights[i];
            }
            else{
                cnt++;
                sum = weights[i];
            }
        }
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high){
            int mid = (low+high)/2;

            if(capacity(weights,mid,days) == true){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
        }
};