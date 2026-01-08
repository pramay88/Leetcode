class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> dp(m, INT_MIN);

        for(int i = 0; i < n; i++){
            vector<int> next(m, INT_MIN);

            for(int j = 0; j < m; j++){
                int curr = nums1[i] * nums2[j];
                int ans = curr; // start fresh

                if(i > 0 && j > 0)
                    ans = max(ans, curr + dp[j - 1]); // extend

                if(i > 0)
                    ans = max(ans, dp[j]); // skip nums1[i]

                if(j > 0)
                    ans = max(ans, next[j - 1]); // skip nums2[j]

                next[j] = ans;
            }
            dp = next;
        }
        return dp[m - 1];
    }
};