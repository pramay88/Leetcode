class Solution {
    bool subsetSum(vector<int> nums, int sum, int n){
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        for(int i=0; i<=n; i++) dp[i][0] = true;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                if(nums[i-1] <= j) dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i=0; i<n; i++) sum += nums[i];
        if(sum & 1) return false;
        return subsetSum(nums, sum/2, n);
    }
};