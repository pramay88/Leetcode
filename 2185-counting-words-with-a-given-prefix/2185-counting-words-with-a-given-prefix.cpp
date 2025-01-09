class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0, len = words.size(), prefLen = pref.length();
        for(string str:words){
            if(str.substr(0,prefLen) == pref)
                count++;
        }
        return count;
    }
};