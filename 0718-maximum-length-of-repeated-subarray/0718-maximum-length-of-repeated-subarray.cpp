class Solution {
    int ans = 0;
    int f(vector<int> & arr1, vector<int> & arr2, int i, int j, vector<vector<int>> &dp){
        if(i == arr1.size() || j == arr2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        int len = 0;

        if(arr1[i] == arr2[j]){
            len = 1 + f(arr1, arr2, i + 1, j + 1, dp);
            ans = max(ans, len);
        }

        f(arr1, arr2, i + 1, j, dp);
        f(arr1, arr2, i, j + 1, dp);

        return dp[i][j] = len;
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        f(nums1, nums2, 0, 0, dp);
        return ans;
    }
};