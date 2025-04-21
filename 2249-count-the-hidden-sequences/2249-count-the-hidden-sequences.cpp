class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long currentSum = 0, minPrefixSum = 0, maxPrefixSum = 0;
        for (int difference : differences) {
            currentSum += difference;
            minPrefixSum = min(minPrefixSum, currentSum);
            maxPrefixSum = max(maxPrefixSum, currentSum);
        }
        return max(upper - lower - (maxPrefixSum - minPrefixSum) + 1, 0LL);
    }
};