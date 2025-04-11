class Solution {
    bool symmetric(int num){
        string s = to_string(num);
        int len = s.length();
        if (len % 2 != 0) return false;

        int n = len / 2;
        int leftSum = 0, rightSum = 0;
        
        for (int i = 0; i < n; ++i) leftSum += s[i] - '0';
        
        for (int i = n; i < len; ++i) rightSum += s[i] - '0';
        
        return leftSum == rightSum;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; ++i) {
            if (symmetric(i)) {
                count++;
            }
        }
        return count;
    }
};