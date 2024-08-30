class Solution {
public:
    bool isSubsequence(string s, string t) {
        int a = s.size(), b = t.size();
        int i = 0, j = 0;
        for (;i<a && j<b;++j) {
            if (s[i] == t[j]) {
                ++i;
            }
        }
        return i == a;
    }
};