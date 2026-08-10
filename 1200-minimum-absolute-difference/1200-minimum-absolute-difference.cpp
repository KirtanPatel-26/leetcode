class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> v;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int ans = INT_MAX;

        for(int i=0;i<n-1;i++){
            int mini = arr[i+1] - arr[i];
            ans = min(ans,mini);
        }
        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i] == ans){
                v.push_back({arr[i],arr[i+1]});
            }
        }
        return v;
    }
};