class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res = "";
        int pLen = part.length();
        for(char &c: s){
            res.push_back(c);
            if(res.length() >= pLen && res.substr(res.length() -pLen) == part)
                res.erase(res.length() - pLen);
        }
        return res;
    }
};