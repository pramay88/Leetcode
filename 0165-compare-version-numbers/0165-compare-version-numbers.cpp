class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, x = 0, y = 0;
        int n = version1.size(), m = version2.size();
        while(i < n || j < m){
            while(i < n &&version1[i] != '.')
                x = x*10 + (version1[i] - '0'), i++;
            while(j < m && version2[j] != '.')
                y = y*10 + (version2[j] - '0'), j++;
            
            if(x < y) return -1;
            else if(x > y) return 1;
            i++, j++, x = 0, y = 0;
        }
        return 0;
    }
};