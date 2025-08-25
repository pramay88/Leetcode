class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};
        
        int n = mat.size();
        int m = mat[0].size();
        vector<int> diagonal;
        diagonal.reserve(n * m);

        int row = 0, col = 0, direction = 1;
        for (int i = 0; i < n * m; i++) {
            diagonal.push_back(mat[row][col]);

            if (direction == 1) {
                if (col == m - 1) {
                    row++;
                    direction = -1;
                } else if (row == 0) {
                    col++;
                    direction = -1;
                } else {
                    row--, col++;
                }
            } else {
                if (row == n - 1) {
                    col++;
                    direction = 1;
                } else if (col == 0) {
                    row++;
                    direction = 1;
                } else {
                    row++, col--;
                }
            }
        }
        return diagonal;
    }
};
