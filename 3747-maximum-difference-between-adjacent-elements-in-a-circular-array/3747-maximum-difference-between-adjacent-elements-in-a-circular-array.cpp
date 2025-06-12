class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = INT_MIN, n = nums.size();
        if (n < 2) return 0;
        for(int i=0; i<n; i++)
            maxDiff = max(maxDiff, abs(nums[i] - nums[(i + 1) % n]));
        return maxDiff;
    }
};