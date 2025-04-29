class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxx = *max_element(nums.begin(), nums.end());
        long long count = 0;
        int win_max = 0, l = 0;;  // no of max_element in window
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == maxx) {
                win_max++;
            }
            while (win_max == k) {
                if (nums[l] == maxx) {
                    win_max--;
                }
                l++;
            }
            count += l;
        }
        return count;
    }
};