class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if((i==0 || j==0 || i==m-1 || j==n-1) && (grid[i][j] == 1)){
                    q.push({i, j});
                    grid[i][j] = 2;
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(auto d: dir){
                int nx = x + d.first, ny = y + d.second;
                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny] == 1){
                    q.push({nx, ny});
                    grid[nx][ny] = 2;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) count++;
                else if(grid[i][j] == 2) grid[i][j] = 1;
            }
        }
        return count;
    }
};