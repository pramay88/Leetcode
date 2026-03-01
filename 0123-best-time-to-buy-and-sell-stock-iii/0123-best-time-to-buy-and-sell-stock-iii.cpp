class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), transactions = 2;

        vector<vector<int>> curr(2, vector<int>(transactions + 1, 0));
        vector<vector<int>> next(2, vector<int>(transactions + 1, 0));


        for(int i = n - 1; i >= 0; i--){
            for(int t = 1; t <= transactions; t++){

                // buyed == 1 → holding → can sell
                curr[1][t] = max(
                    prices[i] + next[0][t - 1],  // sell (transaction completes)
                    next[1][t]                   // hold
                );

                // buyed == 0 → not holding → can buy
                curr[0][t] = max(
                    -prices[i] + next[1][t],     // buy
                    next[0][t]                   // skip
                );
            }
            next = curr;
        }

        return next[0][transactions];
    }
};