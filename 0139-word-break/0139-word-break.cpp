class Solution {
    bool solve(int i, string &s, unordered_set<string> &st, vector<int> &dp) {
        if(i == s.size()) return true;

        if(dp[i] != -1) return dp[i];

        string cur;

        for(int j = i; j < s.size(); j++){
            cur += s[j];
            if(st.count(cur) && solve(j + 1, s, st, dp))
                return dp[i] = true;
        }

        return dp[i] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);

        return solve(0, s, st, dp);
    }
};