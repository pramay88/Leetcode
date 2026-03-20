class Solution {
    vector<vector<int>> vis;
    bool f(vector<vector<char>> & board, int i, int j, string & word, int k){
        int n = board.size(), m = board[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        if(vis[i][j]) return false;
        if(board[i][j] != word[k]) return false;
        
        if(k == word.size() - 1) return true;
        
        vis[i][j] = 1;

        bool found = 
            f(board, i + 1, j, word, k + 1) ||
            f(board, i, j + 1, word, k + 1) ||
            f(board, i - 1, j, word, k + 1) ||
            f(board, i, j - 1, word, k + 1);
        
        vis[i][j] = 0;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vis.assign(n, vector<int>(m, 0));

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