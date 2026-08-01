class Solution {
public:
    int possible(vector<int>& bloomDay, int days, int m, int k){
        int cnt = 0;
        int bouque = 0;
        int n = bloomDay.size();

        for(int i=0;i<n;i++){
            if(bloomDay[i] <= days){
                cnt++;
            }
            else{
                bouque += cnt/k;
                cnt = 0;
            }
        }
        bouque += cnt/k;

        return bouque >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n)
        return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low <= high){
            int mid = (low+high)/2;

            if(possible(bloomDay,mid,m,k) == true){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};