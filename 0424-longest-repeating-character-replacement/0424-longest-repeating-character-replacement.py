class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        left = maxLen = maxCount = 0
        freq = [0] * 26
        for right in range(len(s)):
            freq[ord(s[right]) - ord('A')] += 1
            maxCount = max(maxCount, freq[ord(s[right]) - ord('A')])
            if (right - left + 1) - maxCount > k:
                freq[ord(s[left]) - ord('A')] -= 1
                left += 1
            maxLen = max(maxLen, right - left + 1)
        return maxLen