class Solution {
    bool f(vector<vector<char>> & board, int i, int j, string & word, int k){
        int n = board.size(), m = board[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        if(board[i][j] == '#') return false;
        if(board[i][j] != word[k]) return false;
        
        if(k == word.size() - 1) return true;
        
        char temp = board[i][j];
        board[i][j] = '#';

        bool found = 
            f(board, i + 1, j, word, k + 1) ||
            f(board, i, j + 1, word, k + 1) ||
            f(board, i - 1, j, word, k + 1) ||
            f(board, i, j - 1, word, k + 1);
        
        board[i][j] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    if(f(board, i, j, word, 0)) return true;
                }
            }
        }
        return false;
    }
};