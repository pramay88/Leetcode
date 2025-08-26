class Solution {
public:
    int romanToInt(string s) {
        int res = 0, n = s.length();
        map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for(int i=0; i<n; i++){
            int val = mp[s[i]];
            if(i+1 < n && mp[s[i+1]] > mp[s[i]]) res -= val;
            else res += val;
        }
        return res;
    }
};