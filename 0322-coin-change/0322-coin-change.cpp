class Solution {
    int solve(vector<vector<int>> &dp, vector<int> & coins, int ind, int amount){
        if(ind == 0) return (amount % coins[0] == 0)? amount / coins[0]: 1e9;
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int take = 1e9;
        if(coins[ind] <= amount)
            take = 1 + solve(dp, coins, ind, amount - coins[ind]);
        int notTake = 0 + solve(dp, coins, ind - 1, amount);
        return dp[ind][amount] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(dp, coins, n - 1, amount);
        return (ans >= 1e9)? -1: ans;
    }
};