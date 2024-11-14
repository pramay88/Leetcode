class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = 1e5;
        while (l < r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int& v : quantities) {
                cnt += (v + mid - 1) / mid;
            }
            if (cnt <= n) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;

    }
};