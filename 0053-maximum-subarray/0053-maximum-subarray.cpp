class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, currSum = 0;
        for(int n: nums){
            currSum = max(n, currSum + n);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};