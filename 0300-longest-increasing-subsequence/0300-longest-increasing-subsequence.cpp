class Solution {
    int length(vector<int> & nums, int i, int prev, vector<vector<int>> & dp){
        if(i >= nums.size()) return 0;

        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];

        int take = 0;
        if(prev == - 1 || nums[i] > nums[prev])
            take = 1 + length(nums, i + 1, i, dp);
        
        int notTake = 0 + length(nums, i + 1, prev, dp);

        return dp[i][prev + 1] = max(take, notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return length(nums, 0, -1, dp);
    }
};