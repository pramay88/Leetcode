class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        int mx = INT_MAX;
        for (int num : nums) {
            if (num < k) {
                return -1;
            }
            mx = min(mx, num);
            s.insert(num);
        }
        return s.size() - (mx == k);
    }
};