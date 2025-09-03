class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, maxLen = 0, n = s.size();
        vector<int> lastSeenIndex(128, -1);
        for(int right = 0; right < n; ++right){
            char c = s[right];
            if(lastSeenIndex[c] >= left)
                left = lastSeenIndex[c] + 1;
            lastSeenIndex[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};