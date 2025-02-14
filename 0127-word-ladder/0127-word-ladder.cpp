class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        
        int n = wordList.size();
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        wordSet.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int count = q.front().second;
            q.pop();
            int wordLen = word.length();
            for(int i=0; i<wordLen; i++){
                char originalChar = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == originalChar) continue;
                    word[i] = ch;
                    if (word == endWord) return count + 1;
                    if (wordSet.find(word) != wordSet.end()) {
                        q.push({word, count + 1});
                        wordSet.erase(word);
                    }
                }
                word[i] = originalChar;
            }
        }
        return 0;
    }
};