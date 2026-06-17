class Solution {
public:
    string reverseWords(string s) {
        string word, ans;
        vector<string> words;
        stringstream ss(s);

        while(ss >> word) words.push_back(word);
        
        reverse(words.begin(), words.end());

        for(string &w: words) ans += w + ' ';
        ans.pop_back();
        
        return ans;
    }
};