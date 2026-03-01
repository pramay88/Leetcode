class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), transactions = 2;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(transactions + 1, 0)));
    
        for (int t = 0; t <= transactions; t++)
            dp[0][1][t] = INT_MIN;

        for(int i = 1; i <= n; i++){
            for(int t = 1; t <= transactions; t++){
                
                dp[i][1][t] = max(
                    -prices[i - 1] + dp[i - 1][0][t - 1], // Sell
                    0 + dp[i - 1][1][t]                  // Hold
                );
                dp[i][0][t] = max(
                    prices[i - 1] + dp[i - 1][1][t],  // Buy
                    0 + dp[i - 1][0][t]                // Skip
                );                
            }
        }

        return dp[n][0][transactions];
    }
};