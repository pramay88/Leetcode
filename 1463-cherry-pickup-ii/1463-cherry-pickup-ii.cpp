class Solution {
    int dp[71][71][71];
    int n, m;

    int solve(vector<vector<int>> &grid, int row, int j1, int j2){
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;

        if(dp[row][j1][j2] != -1) return dp[row][j1][j2];

        if(row == n - 1){
            if(j1 == j2) return dp[row][j1][j2] =  grid[row][j1];
            else return dp[row][j1][j2] = grid[row][j1] + grid[row][j2];
        }

        vector<int> dir = {-1, 0, 1};
        int maxx = -1e8;
        for(int x: dir){
            for(int y: dir){
                int cherries = (j1 == j2)? grid[row][j1]: grid[row][j1] + grid[row][j2];
                cherries += solve(grid, row + 1, j1 + x, j2 + y);
                maxx = max(maxx, cherries);
            }
        }
        return dp[row][j1][j2] = maxx;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, m - 1);
    }
};