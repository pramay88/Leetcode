class Solution {
    int expand(string s, int left, int right){
        int n = s.size();
        while(left >= 0 && right < n && s[left] == s[right])
            left--, right++;
        return right - left - 1;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size(), maxLen = 0, start = 0;
        for(int i = 0; i < n; i++){
            int oddLen = expand(s, i, i);
            int evenLen = expand(s, i, i+1);
            
            int len = max(oddLen, evenLen);
            if(len > maxLen){
                maxLen = len;
                start = i - (len - 1)/2;
            }
        }
        return s.substr(start, maxLen);
    }
};