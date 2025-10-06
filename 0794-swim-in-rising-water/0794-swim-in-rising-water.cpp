class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        // Min-heap: {height, x, y}
        priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<>
        > pq;
        
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;
        
        int ans = 0;
        while(!pq.empty()) {
            auto [h, pos] = pq.top(); pq.pop();
            auto [x, y] = pos;
            ans = max(ans, h);            
            if(x == n - 1 && y == n - 1) return ans;
            
            for(auto [dx, dy] : dir) {
                int nx = x + dx, ny = y + dy;
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    pq.push({grid[nx][ny], {nx, ny}});
                }
            }
        }
        return ans;
    }
};