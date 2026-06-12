class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 0, n = s.length();
        string res = "";
        
        // Expand from each index
        for(int i = 0; i < n; i++){
            // Check Odd Length
            int left = i, right = i;
            while(left >= 0 && right < n && s[left] == s[right]){
                if(right - left + 1 > longest){
                    longest = right - left + 1;
                    res = s.substr(left, longest);
                }
                left--, right ++;
            }

            // Check Even Length
            left = i, right = i + 1;
            while(left >= 0 && right < n && s[left] == s[right]){
                if(right - left + 1 > longest){
                    longest = right - left + 1;
                    res = s.substr(left, longest);
                }
                left--, right++;
            }
        }

        return res;
    }
};