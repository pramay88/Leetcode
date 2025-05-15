class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        int n = words.size();
        if (n == 0) return res;

        res.push_back(words[0]);
        int prev = groups[0];

        for (int i = 1; i < n; ++i) {
            if (groups[i] != prev) {
                res.push_back(words[i]);
                prev = groups[i];
            }
        }

        return res;
    }
};