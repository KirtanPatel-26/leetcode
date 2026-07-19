class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        int richest = 0;

        for(int i = 0;i<n;i++){
            int wealth = 0;
            for(int j = 0;j<accounts[i].size();j++){
                wealth += accounts[i][j];
            }
            richest = max(richest,wealth);
        }
        return richest;
    }
};