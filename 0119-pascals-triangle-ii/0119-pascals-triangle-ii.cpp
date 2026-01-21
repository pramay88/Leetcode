class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> tri;
        tri.push_back({1});
        for(int i = 1; i <= rowIndex; i++){
            vector<int> curr(i + 1, 1);
            for(int j = 1; j < i; j++){
                curr[j] = tri[i - 1][j - 1] + tri[i - 1][j];
            }
            tri.push_back(curr);
        }
        return tri.back();
    }
};