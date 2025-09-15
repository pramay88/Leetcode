class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> broken(128,0);
        for(char &c: brokenLetters) broken[c] = 1;
        int count = 0, i = 0;
        while (i < text.length()) {
            bool hasBroken = false;
            while(i < text.length() && text[i] != ' ') {
                if (broken[text[i]]) hasBroken = true;
                i++;
            }
            if (!hasBroken) count++;
            i++;
        }
        return count;
    }
};