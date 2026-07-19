class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, 0);
        for(int i = 0; i < s.length(); i++){
            lastIndex[s[i] - 'a'] = i;
        }
        
        vector<bool> seen(26, false);
        string result = "";
        
        for(int i = 0; i < s.length(); i++){
            int curr = s[i] - 'a';
            if(seen[curr]) continue;
            
            while(!result.empty() && result.back() > s[i] && lastIndex[result.back() - 'a'] > i){
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            result += s[i];
            seen[curr] = true;
        }
        return result;
    }
};