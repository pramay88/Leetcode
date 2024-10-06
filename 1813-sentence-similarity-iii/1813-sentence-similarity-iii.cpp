class Solution {
public:
    vector<string> split(string s,char parameter){
        string str;
        stringstream ss(s);
        vector<string> ans;
        while(getline(ss,str,parameter))
            ans.emplace_back(str);
        return ans;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> w1=split(sentence1,' ');
        vector<string> w2=split(sentence2,' ');
        if (w1.size() < w2.size()) {
            swap(w1, w2);
        }
        int m = w1.size(), n = w2.size();
        int i = 0, j = 0;
        while (i < n && w1[i] == w2[i]) {
            ++i;
        }
        while (j < n && w1[m - 1 - j] == w2[n - 1 - j]) {
            ++j;
        }
        return i + j >= n;

    }
};