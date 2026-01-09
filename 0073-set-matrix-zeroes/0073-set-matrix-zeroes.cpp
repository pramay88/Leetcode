class Solution {
    void makeZero(vector<vector<int>> & mat, int x, int y){
        int n = mat.size(), m = mat[0].size();
        for(int j = 0; j < m; j++) mat[x][j] = 0;
        for(int i = 0; i < n; i++) mat[i][y] = 0;
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> hash(n, vector<int>(m, -1));
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(matrix[i][j] == 0) hash[i][j] = 0;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(hash[i][j] == 0) makeZero(matrix, i, j);
            
    }
};