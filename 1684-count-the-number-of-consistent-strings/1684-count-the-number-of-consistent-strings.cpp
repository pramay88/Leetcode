class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> all(allowed.begin(),allowed.end());
        int count=0;
        for(string word: words){
            bool isConsistent=true;
            for(char c: word){
                if(all.find(c)==all.end()){
                    isConsistent=false;
                    break;
                }
            }
            if(isConsistent)    ++count;
        }
        return count;
    }
};