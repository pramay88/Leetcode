class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(2), curr(2);

        for(int i = n - 1; i >= 0; i--){
            // buyed == false → can buy
            curr[0] = max(
                -prices[i] + next[1],  // buy
                0 + next[0]            // skip
            );
            // buyed == true → can sell
            curr[1] = max(
                prices[i] + next[0],   // sell
                0 + next[1]            // hold
            );
            next = curr;
        }

        return next[0];
    }
};