class Solution {
public:
    int strStr(string str1, string str2){
        int n = str1.size(), m = str2.size();
        if(m == 0) return 0;
        if(m > n) return -1;
        for(int i = 0; i <= n - m; i++){
            int j = 0;
            while(j < m && str1[i + j] == str2[j]) j++;
            if(j == m) return i;
        }
        return -1;
    }
};