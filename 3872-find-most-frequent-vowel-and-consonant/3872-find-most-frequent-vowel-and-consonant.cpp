class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        string vowels = "aeiou";
        for(char &c: s) freq[c - 'a']++;
        int maxC = 0, maxV = 0;
        for (int i = 0; i < 26; ++i) {
            char ch = 'a' + i;
            if (vowels.find(ch) != string::npos)
                maxV = max(maxV, freq[i]);
            else maxC = max(maxC, freq[i]);
        }
        return maxC+maxV;
    }
};