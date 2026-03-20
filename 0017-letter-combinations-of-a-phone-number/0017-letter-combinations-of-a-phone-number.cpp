class Solution {
    vector<string> res;
    unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

    void backtrack(string digits, int i, string comb){
        if(i == digits.length()){
            res.push_back(comb);
            return;
        }
        
        string letters = mp.at(digits[i]);

        for(char letter: letters)
            backtrack(digits, i + 1, comb + letter);
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        backtrack(digits, 0, "");
        return res;
    }
};