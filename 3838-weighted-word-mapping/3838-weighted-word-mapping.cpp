class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = weights.size();
        string res = "";

        for(string &s: words){
            int weight = 0;
            for(char c: s){
                weight += weights[c - 'a'];
            }
            weight %= 26;
            res += 'a' + 25 - weight;
        }
        
        return res;
    }
};