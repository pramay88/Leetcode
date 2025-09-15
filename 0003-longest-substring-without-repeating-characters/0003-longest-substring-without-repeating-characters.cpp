class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int charFrequency[128] = {0};      
        int maxLength = 0, n = s.size(), left = 0;

        for (int right = 0; right < n; ++right) {
            ++charFrequency[s[right]];          
            while (charFrequency[s[right]] > 1) {
                --charFrequency[s[left]];
                ++left;
            }          
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};