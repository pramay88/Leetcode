class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long N = n * n;
        long long expectedSum = (N * (N + 1)) / 2;
        long long expectedSumSq = (N * (N + 1) * (2 * N + 1)) / 6;
        
        long long actualSum = 0, actualSumSq = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                long long num = grid[i][j];
                actualSum += num;
                actualSumSq += (num * num);
            }
        }
    
        long long diff = actualSum - expectedSum;
        long long sumSqDiff = actualSumSq - expectedSumSq; 

        long long sum = sumSqDiff / diff;
        
        int a = (diff + sum) / 2;
        int b = sum - a;
        
        return {a, b};
    }
};