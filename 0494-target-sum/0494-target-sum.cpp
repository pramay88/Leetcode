class Solution {
    int countSubsets(vector<int>& arr, int n, int sum){
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i-1][j];
                if (arr[i-1] <= j)
                    dp[i][j] += dp[i-1][j - arr[i-1]];
            }
        }
        return dp[n][sum];
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > sum) return 0;
        if ((sum + target) % 2) return 0;

        int reqSum = (sum + target) / 2;
        return countSubsets(nums, n, reqSum);
    }
};