class Solution {
    int find(vector<vector<int>> &grid, int x, int y, int k){
    vector<int> vals;

    for(int i = x; i < x + k; i++)
        for(int j = y; j < y + k; j++)
            vals.push_back(grid[i][j]);

    sort(vals.begin(), vals.end());

    int minDiff = INT_MAX;

    for(int i = 1; i < vals.size(); i++)
        if(vals[i] != vals[i-1])
            minDiff = min(minDiff, vals[i] - vals[i-1]);

    return (minDiff == INT_MAX) ? 0 : minDiff;
}
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));

        for(int i = 0; i < n - k + 1; i++)
            for(int j = 0; j < m - k + 1; j++)
                ans[i][j] = find(grid, i, j, k);
                
        return ans;
    }
};