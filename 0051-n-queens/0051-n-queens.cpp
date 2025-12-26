class Solution {
    bool safeToFill(int row, int col, vector<string>& sol, int n) {
        int duprow = row, dupcol = col;

        while (col >= 0) {
            if (sol[row][col] == 'Q') return false;
            col--;
        }

        row = duprow, col = dupcol;
        while (row >= 0 && col >= 0) {
            if (sol[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = duprow, col = dupcol;
        while (row < n && col >= 0) {
            if (sol[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }

    void find(int col, int n, vector<vector<string>> &board, vector<string> &sol){
        if(col >= n){
            board.push_back(sol);
            return;
        }
        for(int i = 0; i < n; i++){
            if(safeToFill(i, col, sol, n)){
                sol[i][col] = 'Q';
                find(col+1, n, board, sol);
                sol[i][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board;
        vector<string> sol(n, string(n, '.'));
        find(0, n, board, sol);
        return board;
    }
};