class Solution {
    double solve(int champagne, int r, int c, vector<vector<double>> & dp){
        if(c < 0 || c > r) return 0.0;
        if(r == 0 && c == 0) return champagne;
        
        if(dp[r][c] != -1.0) return dp[r][c];

        double leftParent  = solve(champagne, r - 1, c - 1, dp);
        double rightParent = solve(champagne, r - 1, c, dp);

        double fromLeft  = max(0.0, (leftParent - 1.0) / 2.0);
        double fromRight = max(0.0, (rightParent - 1.0) / 2.0);

        return dp[r][c] = fromLeft + fromRight;
    }

public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101, vector<double>(101, -1.0));
        return min(1.0, solve(poured, query_row, query_glass, dp));
    }
};
