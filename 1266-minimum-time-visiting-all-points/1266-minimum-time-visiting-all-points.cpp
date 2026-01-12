class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int minn = 0;
        int prevX = points[0][0], prevY = points[0][1];
        for(int i = 1; i < points.size(); i++){
            int x = points[i][0], y = points[i][1];
            int dx = abs(x - prevX), dy = abs(y - prevY);
            int d = max(dx, dy);
            minn += d;
            prevX = x, prevY = y;
        }
        return minn;
    }
};