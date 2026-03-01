class Solution {
    int cool;
    vector<vector<int>> dp;

    int profit(vector<int> & prices, int i, int n, bool buyed){
        if(i >= n) return 0;

        if(dp[i][buyed] != -1) return dp[i][buyed];

        // Already Bought -> can sell
        if(buyed)
            return dp[i][buyed] = max(
                prices[i] + profit(prices, i + 1 + cool, n, false),
                0 + profit(prices, i + 1, n, true)
            );
        
        // Not Bought - > can buy
        else return dp[i][buyed] = max(
            -prices[i] + profit(prices, i + 1, n, true),     // buyed
            0 + profit(prices, i + 1, n, false)              // Skip
        );
    }
    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        cool = 1;
        dp.resize(n, vector<int>(2, -1));

        return profit(prices, 0, n, false);
    }
};