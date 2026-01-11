class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s.begin(), s.end());

        vector<int> dp(n + 1, 0);

        for(int i = 1; i <= n; i++){
            int prev = 0;
            for(int j = 1; j <= n; j++){
                int match = 0, temp = dp[j];
                
                if(s1[i - 1] == s[j - 1]) match = 1 + prev;
                int nM = 0 + max(dp[j], dp[j - 1]);
                dp[j] = max(match, nM);
                
                prev = temp;
            }
        }
        return dp[n];
    }
};