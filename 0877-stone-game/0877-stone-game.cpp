class Solution {
public:
    vector<vector<int>> dp;

    int game(vector<int>& piles, int i, int j) {
        if (i > j)
            return 0;

        if (i == j)
            return piles[i];

        if (dp[i][j] != -1)
            return dp[i][j];

        int left = piles[i] - game(piles, i + 1, j);
        int right = piles[j] - game(piles, i, j - 1);

        return dp[i][j] = max(left, right);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int>(n, -1));

        return game(piles, 0, n - 1) > 0;
    }
};