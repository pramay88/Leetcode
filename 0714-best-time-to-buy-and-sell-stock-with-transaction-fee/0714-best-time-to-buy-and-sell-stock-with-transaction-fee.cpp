class Solution {
    vector<vector<int>> dp;
    int profit(vector<int> & prices, int i, int n, int buyed, int fee){
        if(i >= n) return 0;

        if(dp[i][buyed] != -1) return dp[i][buyed];

        if(buyed)
            return dp[i][buyed] = max(
                prices[i] - fee + profit(prices, i + 1, n, false, fee),
                0 + profit(prices, i + 1, n, true, fee)
            );
        else return dp[i][buyed] = max(
            -prices[i] + profit(prices, i + 1, n, true, fee),
            0 + profit(prices, i + 1, n, false, fee)
        );
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        dp.resize(n, vector<int>(2, -1));
        
        return profit(prices, 0, n, false, fee);
    }
};