class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor == color) return image; 
        
        int m = image.size(), n = image[0].size();
        vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(auto d: dir){
                int nx = x + d.first, ny = y + d.second;
                if(nx>=0 && nx<m && ny>=0 && ny<n && (image[nx][ny] == originalColor)){
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};