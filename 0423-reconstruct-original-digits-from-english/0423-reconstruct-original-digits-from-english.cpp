class Solution {
public:
    string originalDigits(string s) {
        int cnt[26] = {}, digit[10] = {};

        for(char c : s)
            cnt[c - 'a']++;

        // Digits with unique identifying characters
        digit[0] = cnt['z' - 'a']; // zero
        digit[2] = cnt['w' - 'a']; // two
        digit[4] = cnt['u' - 'a']; // four
        digit[6] = cnt['x' - 'a']; // six
        digit[8] = cnt['g' - 'a']; // eight

        // Remaining digits
        digit[1] = cnt['o' - 'a'] - digit[0] - digit[2] - digit[4];
        digit[3] = cnt['h' - 'a'] - digit[8];
        digit[5] = cnt['f' - 'a'] - digit[4];
        digit[7] = cnt['s' - 'a'] - digit[6];
        digit[9] = cnt['i' - 'a'] - digit[5] - digit[6] - digit[8];

        string ans;

        for(int d = 0; d <= 9; d++){
            ans += string(digit[d], char('0' + d));
        }

        return ans;
    }
};