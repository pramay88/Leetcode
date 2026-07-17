class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int word = 1;
        int n = sentence.size();
        int m = searchWord.size();

        int i = 0;
        while (i < n){
            if(i == 0 || sentence[i - 1] == ' '){
                int k = i, j = 0;

                while(k < n && sentence[k] != ' ' && j < m && sentence[k] == searchWord[j]){
                    k++;
                    j++;
                }
                if(j == m) return word;
                word++;
            }
            i++;
        }

        return -1;
    }
};