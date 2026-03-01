class Solution {
    vector<vector<vector<int>>> dp;
    int profit(vector<int> & prices, int i, int n, int buyed, int k){
        if(i == n || k == 0) return 0;

        if(dp[i][buyed][k] != -1) return dp[i][buyed][k];

        if(buyed)
            return dp[i][buyed][k] = max(
                prices[i] + profit(prices, i + 1, n, false, k - 1),
                0 + profit(prices, i + 1, n, true, k)
            );
            
        else return dp[i][buyed][k] = max(
                -prices[i] + profit(prices, i + 1, n, true, k),
                0 + profit(prices, i + 1, n, false, k)
        );
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.resize(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));

        return profit(prices, 0, prices.size(), false, k);
    }
};