class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count = 0, n = text.length(), i = 0, words = 0;
        vector<int> broken(128,0);
        for(char &c: brokenLetters) broken[c]++;
        while(i < n){
            if(broken[text[i]]){
                count++;
                while(i+1 < n && text[i+1] != ' ') i++;
            }
            else if(text[i] == ' ')
                words++;
            i++;
        }
        return words - count + 1;
    }
};