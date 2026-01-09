class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, 1e9), curr(amount + 1, 1e9);
        for(int j = 0; j <= amount; j++) if(j % coins[0] == 0) dp[j] = j / coins[0];
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= amount; j++){
                int notTake = 0 + dp[j];
                int take = 1e9;
                if(coins[i] <= j) take = 1 + curr[j - coins[i]];
                curr[j] = min(take, notTake);
            }
            dp = curr;
        }
        int ans = dp[amount];
        return (ans >= 1e9)? -1: ans;
    }
};