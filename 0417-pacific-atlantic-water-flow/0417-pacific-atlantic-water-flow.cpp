class Solution {
    vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int n, m;
    void bfs(queue<pair<int, int>> &q, vector<vector<int>> &vis, vector<vector<int>> &heights){
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            for(auto [dx, dy]: dir){
                int nx = x + dx, ny = y + dy;
                if(nx>=0 && nx<n && ny>=0 && ny<m && heights[nx][ny] >= heights[x][y] && !vis[nx][ny]){
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        vector<vector<int>> pacific(n, vector<int>(m, 0)), atlantic(n, vector<int>(m, 0));
        queue<pair<int, int>> qPacific, qAtlantic;
        
        // pacific borders (top and left)
        for(int i = 0; i < n; i++) qPacific.push({i, 0}), pacific[i][0] = 1;
        for(int j = 0; j < m; j++) qPacific.push({0, j}), pacific[0][j] = 1;
        
        // Atlantic borders (bottom + right)
        for(int i = 0; i < n; i++) qAtlantic.push({i, m-1}), atlantic[i][m-1] = 1;
        for(int j = 0; j < m; j++) qAtlantic.push({n-1, j}), atlantic[n-1][j] = 1;

        bfs(qPacific, pacific, heights);
        bfs(qAtlantic, atlantic, heights);

        vector<vector<int>> result;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
            if(pacific[i][j] && atlantic[i][j]) result.push_back({i, j});
        
        return result;
    }
};