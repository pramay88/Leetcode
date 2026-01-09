class Solution {
    int solve(vector<vector<int>> & dp, const vector<int> &coins, int amount, int ind){
        if(amount == 0) return 1;
        if(ind == 0) return amount % coins[0] == 0;
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int take = 0;
        if(coins[ind] <= amount) take = solve(dp, coins, amount - coins[ind], ind);
        int nT = solve(dp, coins, amount, ind - 1);
        return dp[ind][amount] = take + nT;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(dp, coins, amount, n - 1);
    }
};