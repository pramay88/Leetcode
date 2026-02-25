class Solution {
    int lcs(string s1, string s2, int n, int m, vector<vector<int>> &dp){
        if(n < 0 || m < 0) return 0;

        if(dp[n][m] != -1) return dp[n][m];
        
        int match = 0;
        if(s1[n] == s2[m]) match = 1 + lcs(s1, s2, n - 1, m - 1, dp);
        int notMatch = 0 + max(lcs(s1, s2, n - 1, m, dp), lcs(s1, s2, n, m - 1, dp));
        
        return dp[n][m] = max(match, notMatch);
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return n + m - lcs(word1, word2, n - 1, m - 1, dp) * 2;
    }
};