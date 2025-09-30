class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, maxLen = 0, n = s.size(), maxCount = 0;
        int freq[26] = {0};
        for(int right = 0; right < n; right++){
            freq[s[right] - 'A']++;
            maxCount = max(maxCount, freq[s[right] - 'A']);
            if((right - left + 1) - maxCount> k){
                freq[s[left] - 'A']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};