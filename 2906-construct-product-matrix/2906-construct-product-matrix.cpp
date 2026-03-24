class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), zeros = 0, MOD = 12345;

        vector<int> flat;
        for(auto & row: grid)
            for(int & x: row)
                flat.push_back(x % MOD);

        int size = flat.size();
        vector<int> res(size, 1);

        int prefix = 1;
        for(int i = 0; i < size; i++){
            res[i] = prefix;
            prefix = (prefix * flat[i]) % MOD;
        }

        int suffix = 1;
        for(int i = size - 1; i >= 0; i--){
            res[i] = (res[i] * suffix) % MOD;
            suffix = (suffix * flat[i]) % MOD;
        }

        vector<vector<int>> p(n, vector<int>(m));
        
        int idx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                p[i][j] = res[idx++];
            }
        }

        return p;
    }
};