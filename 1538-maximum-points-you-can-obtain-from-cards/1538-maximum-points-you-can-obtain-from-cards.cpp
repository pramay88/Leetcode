class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        long long totalSum = 0, windowSum = 0;
        for(int x : cardPoints) totalSum += x;
        int windowSize = n - k;

        for(int i = 0; i < windowSize; i++) windowSum += cardPoints[i];
        
        long long minWindowSum = windowSum;
        for(int i = windowSize; i < n; i++) {
            windowSum += cardPoints[i] - cardPoints[i - windowSize];
            minWindowSum = min(minWindowSum, windowSum);
        }

        return totalSum - minWindowSum;
    }
};