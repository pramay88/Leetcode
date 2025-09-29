class Solution {
    private int expand(String s, int left, int right){
        int n = s.length();
        while(left >= 0 && right < n && s.charAt(left) == s.charAt(right)){
            left--; right++;
        }
        return right - left - 1;
    }

    public String longestPalindrome(String s) {
        int start = 0, maxLen = 0, n = s.length();
        for(int i = 0; i< n; i++){
            int oddLen = expand(s, i, i);
            int evenLen = expand(s, i, i+1);
            int len = Math.max(oddLen, evenLen);
            if(len > maxLen){
                maxLen = len;
                start = i - (maxLen - 1)/2;
            }
        }
        return s.substring(start, start + maxLen);
    }
}