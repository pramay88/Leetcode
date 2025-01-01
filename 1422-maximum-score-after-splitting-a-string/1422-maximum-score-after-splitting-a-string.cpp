class Solution {
public:
    int maxScore(string s) {
        int lSum = 0, rSum=0, maxSum=0, n=s.length();
        for(char c:s){
            if(c=='1')
                rSum++;
        }
        for(int i = 0; i < n - 1; i++){
            if (s[i] == '0') {
                lSum++;
            }
            if (s[i] == '1') {
                rSum--;
            }
            maxSum = max(maxSum, lSum + rSum);
        }
        return maxSum;
    }
};