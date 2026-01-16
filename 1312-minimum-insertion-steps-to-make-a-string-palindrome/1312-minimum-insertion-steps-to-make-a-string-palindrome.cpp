class Solution {
public:
    int minInsertions(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.size();
        vector<int> dp(n + 1, 0), curr(n + 1, 0);
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == rev[j - 1]) curr[j] = 1 + dp[j - 1];
                else curr[j] = max(dp[j], curr[j - 1]);
            }
            dp = curr;
        }

        return n - dp[n];
    }
};