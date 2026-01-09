class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        for(int &n: nums) sum += n;
        
        if(sum < abs(target) || (sum - target) % 2 != 0) return 0;
        
        int t = (sum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(t + 1, 0));
        
        //base case
        if(nums[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;

        if (nums[0] != 0 && nums[0] <= t)
        dp[0][nums[0]] = 1;


        for(int i = 1; i < n; i++){
            for(int j = 0; j <= t; j++){
                int take = 0;
                if(nums[i] <= j) take = dp[i - 1][j - nums[i]];
                int notTake = dp[i - 1][j];
                dp[i][j] = take + notTake;
            }
        }

        return dp[n - 1][t];
    }
};