class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string,int> hash;
        string str;
        for(char c: s1){
            if(c!=' '){
                str+=c;
            }
            else{
                hash[str]++;
                str="";
            }
        }
        hash[str]++;
        str="";
        for(char c: s2){
            if(c!=' '){
                str+=c;
            }
            else{
                hash[str]++;
                str="";
            }
        }
        hash[str]++;
        for(auto i: hash){
            if(i.second==1)
                ans.emplace_back(i.first);
        }
        return ans;
    }
};