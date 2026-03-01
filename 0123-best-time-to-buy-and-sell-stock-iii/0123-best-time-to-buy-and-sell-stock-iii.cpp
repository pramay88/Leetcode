class Solution {
    vector<vector<vector<int>>> dp;

    int profit(vector<int> & prices, int i, int n, int buyed, int transactions){
        if(transactions <= 0) return 0;     // No Transactions remaining
        if(i == n) return 0;

        if(dp[i][buyed][transactions] != -1) return dp[i][buyed][transactions];
        
        if(buyed)   // Can Sell
            return dp[i][buyed][transactions] = max(
                prices[i] + profit(prices, i + 1, n, false, transactions - 1), // Sell
                0 + profit(prices, i + 1, n, true, transactions)               // Hold
            );

        // Can Buy
        else return dp[i][buyed][transactions] = max(
            -prices[i] + profit(prices, i + 1, n, true, transactions),  // Buy
            0 + profit(prices, i + 1, n, false, transactions)           // Skip
        );
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), transactions = 2;
        dp.resize(n, vector<vector<int>>(2, vector<int>(transactions + 1, -1)));
        return profit(prices, 0, prices.size(), false, 2);
    }
};