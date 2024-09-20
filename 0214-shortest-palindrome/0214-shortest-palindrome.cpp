class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.empty())   return "";
        
        string rev = s; 
        reverse(rev.begin(), rev.end());
        string newString = s + "#" + rev;
        
        vector<int> lps(newString.size(), 0);
        for (int i = 1; i < newString.size(); ++i) {
            int j = lps[i - 1];
            while (j > 0 && newString[i] != newString[j]) {
                j = lps[j - 1];
            }
            if (newString[i] == newString[j]) {
                j++;
            }
            lps[i] = j;
        }

        int longestPalinPrefixLen = lps.back();
        
        string toAdd = s.substr(longestPalinPrefixLen);
        reverse(toAdd.begin(), toAdd.end());
        
        return toAdd + s;

    }
};