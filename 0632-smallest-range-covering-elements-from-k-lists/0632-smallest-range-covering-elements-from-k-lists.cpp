class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = 0;
        for (auto& v : nums) n += v.size();
        vector<pair<int, int>> t(n);
        int k = nums.size();
        for (int i = 0, j = 0; i < k; ++i) {
            for (int v : nums[i]) {
                t[j++] = {v, i};
            }
        }
        int j = 0;
        sort(t.begin(), t.end());
        unordered_map<int, int> count;
        vector<int> res = {-1000000, 1000000};
        for (int i = 0; i < n; ++i) {
            int b = t[i].first;
            int v = t[i].second;
            ++count[v];
            while (count.size() == k) {
                int a = t[j].first;
                int w = t[j].second;
                int x = b - a - (res[1] - res[0]);
                if (x < 0 || (x == 0 && a < res[0])) {
                    res[0] = a;
                    res[1] = b;
                }
                if (--count[w] == 0) {
                    count.erase(w);
                }
                ++j;
            }
        }
        return res;
    }
};