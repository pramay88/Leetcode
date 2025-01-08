class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2){
        int len1 = str1.length(), len2 = str2.length();
        if(len2<len1)   return false;
        string pref = str2.substr(0,len1);
        string suff = str2.substr(len2-len1,len1);
        return (str1 == pref) && (str1 == suff);
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0, n = words.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isPrefixAndSuffix(words[i],words[j]))
                    count++;
            }
        }
        return count;
    }
};