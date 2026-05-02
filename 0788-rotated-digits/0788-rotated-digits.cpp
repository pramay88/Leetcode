class Solution {
    string s;
    int dp[12][2][2]; // [pos, tight, changed]

    bool valid[10] = {true, true, true, false, false, true, true, false, true, true};
    bool diff[10]  = {false, false, true, false, false, true, true, false, false, true};

    int dfs(int pos, int tight, int changed){
        if(pos == s.size()) return changed ? 1 : 0;

        if(dp[pos][tight][changed] != -1)
            return dp[pos][tight][changed];

        int limit = tight ? (s[pos] - '0') : 9;
        int res = 0;

        for(int d = 0; d <= limit; d++){
            if(!valid[d]) continue;

            int newTight = (tight && (d == limit)) ? 1 : 0;
            int newChanged = changed || diff[d];

            res += dfs(pos + 1, newTight, newChanged);
        }

        return dp[pos][tight][changed] = res;
    }
public:
    int rotatedDigits(int n) {
        s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return dfs(0, 1, 0);
    }
};