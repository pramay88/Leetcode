class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> count;
        int res = 0;
        for (auto row : matrix){
            string s;
            for (int x : row) {
                s.push_back('0' + (row[0] == 0 ? x : x ^ 1));
            }
            res = max(res, ++count[s]);
        }
        return res;
    }
};