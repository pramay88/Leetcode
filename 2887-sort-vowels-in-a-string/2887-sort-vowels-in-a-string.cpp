class Solution {
    bool isVowel(char c) {
        static const string vowels = "aeiouAEIOU";
        return vowels.find(c) != string::npos;
    }
public:
    string sortVowels(string s) {
        vector<int> freq(128, 0);
        vector<char> order = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};        
        for (char c : s) if (isVowel(c)) freq[c]++;

        int idx = 0;
        for (char& c : s) {
            if (isVowel(c)) {
                while (idx < order.size() && freq[order[idx]] == 0) idx++;
                c = order[idx];
                freq[order[idx]]--;
            }
        }
        return s;
    }
};