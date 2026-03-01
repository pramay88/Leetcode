class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(2, 0), next(2, 0);

        for(int i = n - 1; i >= 0; i--){
            
            curr[1] = max(
                prices[i] - fee + next[0],
                0 + next[1]
            );

            curr[0] = max(
                -prices[i] + next[1],
                next[0]
            );

            next = curr;
        }

        return next[0];
    }
};