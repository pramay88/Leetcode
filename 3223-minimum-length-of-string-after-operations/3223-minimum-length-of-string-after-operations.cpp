class Solution {
public:
    int minimumLength(string s) {
        vector<int> hash(26,0);
        for(char c: s )
            hash[c-'a']++;
        int count = 0;
        for(int i=0; i<26; i++){
            if(hash[i] > 2){
                count += (hash[i] - 1)/2;
            }
        }
        return s.length() - 2*count;

    }
};