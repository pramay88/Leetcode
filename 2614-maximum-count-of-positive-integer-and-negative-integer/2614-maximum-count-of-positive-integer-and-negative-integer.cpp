class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n, firstPos = n, lastNeg = -1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > 0) {
                firstPos = mid;
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        left = 0, right = n, lastNeg = -1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0) {
                lastNeg = mid;
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        int negCount = lastNeg + 1;
        int posCount = n - firstPos;

        return max(negCount, posCount);
    }
};