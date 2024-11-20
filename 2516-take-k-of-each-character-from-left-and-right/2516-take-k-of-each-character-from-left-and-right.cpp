class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.length();
        int count[3]={0};
        for(char c: s){
            count[c-'a']++;
        }
        for (int x : count) {
            if (x < k) 
                return -1;
        }
        int mx = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            --count[c];
            while (count[c] < k) {
                ++count[s[j++] - 'a'];
            }
            mx = max(mx, i - j + 1);
        }
        return n - mx;     
    }
};