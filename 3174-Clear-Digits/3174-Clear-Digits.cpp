class Solution {
public:
    string clearDigits(string s) {
        int n = s.length(), i = 0 ;
        while(i<n){
            if(s[i] >= '0' && s[i] <= '9'){
                s.erase(i,1);
                n--;
                if(i-1 >= 0){
                    s.erase(i-1, 1);
                    n--;
                    i--;
                }
            }
            else i++;
        }
        return s;
    }
};
