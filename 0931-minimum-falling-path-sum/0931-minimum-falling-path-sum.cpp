class Solution {
    const int INF = 1e9;
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, - 1));
        
        for(int i = 0; i < n; i++) dp[0][i] = matrix[0][i];

        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                int left = (j > 0)? dp[i - 1][j - 1]: INF;
                int right = (j + 1 < n)? dp[i - 1][j + 1]: INF;
                int up = dp[i - 1][j];

                dp[i][j] = matrix[i][j] + min(up, min(left, right));
            }
        }
        
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};