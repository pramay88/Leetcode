class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        vector<vector<int>> next(2, vector<int>(k + 1, 0));
        
        for(int i = n - 1; i >= 0; i--){
            for(int t = 1; t <= k; t++){
                
                curr[1][t] = max(
                    prices[i] + next[0][t - 1],
                    0 + next[1][t]
                );

                curr[0][t] = max(
                    -prices[i] + next[1][t],
                    0 + next[0][t]
                );
            }
            next = curr;
        }
        return next[0][k];
    }
};