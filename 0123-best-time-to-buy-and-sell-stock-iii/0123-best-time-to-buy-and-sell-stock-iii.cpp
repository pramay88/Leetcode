class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), transactions = 2;

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(transactions + 1, 0)));

        for(int i = n - 1; i >= 0; i--){
            for(int t = 1; t <= transactions; t++){

                // buyed == 1 → holding → can sell
                dp[i][1][t] = max(
                    prices[i] + dp[i + 1][0][t - 1],  // sell (transaction completes)
                    dp[i + 1][1][t]                   // hold
                );

                // buyed == 0 → not holding → can buy
                dp[i][0][t] = max(
                    -prices[i] + dp[i + 1][1][t],     // buy
                    dp[i + 1][0][t]                   // skip
                );
            }
        }

        return dp[0][0][transactions];
    }
};