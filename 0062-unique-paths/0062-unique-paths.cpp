class Solution {
    int solve(vector<vector<int>> &dp, int m, int n){
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        int down = solve(dp, m - 1, n);
        int right = solve(dp, m, n - 1);
        return dp[m][n] = down + right;
        
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(dp, m - 1, n - 1);
    }
};