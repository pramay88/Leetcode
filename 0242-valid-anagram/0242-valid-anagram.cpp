class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash;
        if(s.length() != t.length()) return false;
        for (char c : s) {
            hash[c]++;
        }
        for (char c : t) {
            hash[c]--;
            if (hash[c] == 0) {
                hash.erase(c);
            }
        }
        return hash.empty();
    }
};