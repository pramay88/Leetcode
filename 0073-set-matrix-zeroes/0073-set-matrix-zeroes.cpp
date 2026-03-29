class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> row(m, -1), col(n, -1);
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(matrix[i][j] == 0) col[i] = 0, row[j] = 0;
        
        for(int i = 0; i < n; i++)
            if(col[i] == 0)
                for(int j = 0; j < m; j++) matrix[i][j] = 0;

        for(int j = 0; j < m; j++)
            if(row[j] == 0)
                for(int i = 0; i < n; i++) matrix[i][j] = 0;            
    }
};