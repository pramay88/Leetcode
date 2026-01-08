class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.push_back({1});
        for(int i = 1; i < numRows; i++){
            vector<int> curr(i + 1, 1), prev = triangle.back();
            for(int j = 1; j < i; j++)
                curr[j] = prev[j - 1] + prev[j];
            triangle.push_back(curr);
        }
        return triangle;
    }
};