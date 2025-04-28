class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long sums[n + 1];
        sums[0] = 0;
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        long long count = 0;
        for (int i = 1; i <= n; ++i) {
            int l = 0, r = i;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if ((sums[i] - sums[i - mid]) * mid < k) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            count += l;
        }
        return count;
    }
};