class Solution {
    int f(vector<int> & val, int i, int n, bool buyed, vector<vector<int>> & dp){
        if(i >= n) return 0;
        if(dp[i][buyed] != -1) return dp[i][buyed];
        if(buyed){
            return dp[i][buyed] = max(
                val[i] + f(val, i + 1,n,  false, dp),
                0 + f(val, i + 1, n, true, dp)
            );
        }
        else{
            return dp[i][buyed] = max(
                -val[i] + f(val, i + 1, n, true, dp),
                0 + f(val, i + 1, n, false, dp)
            );
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(prices, 0, prices.size(), false, dp);
    }
};