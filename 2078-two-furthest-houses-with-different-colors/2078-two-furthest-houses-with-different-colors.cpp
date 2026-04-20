class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size(), dist = 0;

        for(int i = 0; i < n; i++){
            if(colors[i] != colors[n - 1])
                dist = max(dist, n - 1 - i);
            if(colors[i] != colors[0])
                dist = max(dist, i);
        }

        return dist;
    }
};