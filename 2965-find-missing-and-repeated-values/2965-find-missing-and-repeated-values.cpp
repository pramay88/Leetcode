class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long total = 1LL * n * n;
        long long expectedSum = total * (total + 1) / 2;
        long long expectedSqSum = total * (total + 1) * (2 * total + 1) / 6;
        long long actualSum = 0, actualSqSum = 0;

        for(const auto& row : grid) {
            for(int num : row) {
                actualSum += num;
                actualSqSum += 1LL * num * num;
            }
        }

        long long diff = actualSum - expectedSum;
        long long sqDiff = actualSqSum - expectedSqSum;

        long long sum = sqDiff / diff;

        int repeating = (diff + sum) / 2;
        int missing = sum - repeating;

        return {repeating, missing};
    }
};