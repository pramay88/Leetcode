class Solution {
    bool check(const string& str, int i, int x) {
        int m = str.size();
        if (i >= m) {
            return x == 0;
        }
        int y = 0;
        for (int j = i; j < m; ++j) {
            y = y * 10 + str[j] - '0';
            if (y > x) {
                break;
            }
            if (check(str, j + 1, x - y)) {
                return true;
            }
        }
        return false;
    }
public:
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            int x = i * i;
            string s = to_string(x);
            if (check(s, 0, i)) {
                res += x;
            }
        }
        return res;
    }
};