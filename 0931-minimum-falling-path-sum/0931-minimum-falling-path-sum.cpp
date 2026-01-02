class Solution {
    const int INF = 1e9;
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp = matrix[0];

        for(int i = 1; i < n; i++){
            vector<int> temp(n, -1);
            for(int j = 0; j < n; j++){
                int left = (j > 0)? dp[j - 1]: INF;
                int right = (j + 1 < n)? dp[j + 1]: INF;
                int up = dp[j];

                temp[j] = matrix[i][j] + min(up, min(left, right));
            }
            dp = temp;
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};