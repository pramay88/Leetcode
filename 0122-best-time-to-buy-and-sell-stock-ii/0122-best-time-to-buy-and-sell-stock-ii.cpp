class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for(int i = n - 1; i >= 0; i--){
            // buyed == false → can buy
            dp[i][0] = max(
                -prices[i] + dp[i + 1][1],  // buy
                0 + dp[i + 1][0]            // skip
            );
            // buyed == true → can sell
            dp[i][1] = max(
                prices[i] + dp[i + 1][0],   // sell
                0 + dp[i + 1][1]            // hold
            );
        }

        return dp[0][0];
    }
};