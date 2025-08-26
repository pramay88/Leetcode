class Solution {
public:
    int romanToInt(string s) {
        int res = 0, n = s.length();
        int values[256] = {0};
        values['I'] = 1;
        values['V'] = 5;
        values['X'] = 10;
        values['L'] = 50;
        values['C'] = 100;
        values['D'] = 500;
        values['M'] = 1000;

        for(int i=0; i<n; i++){
            int val = values[s[i]];
            if(i+1 < n && values[s[i+1]] > values[s[i]]) res -= val;
            else res += val;
        }
        return res; 
    }
};