class Solution {
public:
    int checkPrefix(vector<string> words,string prefix){
        int count = 0;
        for(string word : words ){
            if(word.substr(0, prefix.size()) == prefix){
                count++;
            }
        }
        return count;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<string,int> prefixCount;
        vector<int> ans;
        for(string word: words){
            string prefix = "";
            for(char c: word){
                prefix += c;
                prefixCount[prefix]++;
            }
        }
       for(string word: words){
       int score=0;
       string prefix="";
       for(char c: word){
           prefix+=c;
           score += prefixCount[prefix]; 
       }
       ans.push_back(score);
       }
       return ans;
    }
};