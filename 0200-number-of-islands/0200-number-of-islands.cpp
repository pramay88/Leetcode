class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size(), m = grid[0].size();
        vector<pair<int, int>> dir = {{0,1}, {1,0}, {0, -1}, {-1,0}};
        
        for(int i = 0; i <n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(!q.empty()){
                        auto [x, y] = q.front(); q.pop();
                        for(auto [dx, dy]: dir){
                            int nx = x + dx, ny = y + dy;
                            if(nx >=0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1' ){
                                grid[nx][ny] = 0;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};