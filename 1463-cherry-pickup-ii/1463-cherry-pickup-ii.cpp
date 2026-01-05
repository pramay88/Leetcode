class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1))
        );

        for(int j1 = 0; j1 < m; j1++){
            for(int j2 = 0; j2 < m; j2++){
                if(j1 == j2) dp[n - 1][j1][j2] =  grid[n - 1][j1];
                else dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        for(int row = n - 2; row >= 0; row--){
            for(int j1 = 0; j1 < m; j1++){
                for(int j2 = 0; j2 < m; j2++){
                    vector<int> dir = {-1, 0, 1};
                    int maxx = -1e8;
                    for(int x: dir){
                        for(int y: dir){
                            int cherries = (j1 == j2)? grid[row][j1]: grid[row][j1] + grid[row][j2];
                            if(j1 + x >= 0 && j1 + x < m && j2 + y >= 0 && j2 + y < m)
                                cherries += dp[row + 1][j1 + x][j2 + y];
                            else cherries += -1e8;
                            maxx = max(maxx, cherries);
                        }
                    }
                    dp[row][j1][j2] = maxx;
                }
            }
        }
        return dp[0][0][m-1];
    }
};