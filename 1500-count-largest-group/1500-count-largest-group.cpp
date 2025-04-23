class Solution {
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        int count[40] = {}, maxSize = 0;
        for (int i = 1; i <= n; ++i)
            maxSize = max(maxSize, ++count[digitSum(i)]);
        
        int res = 0;
        for (int c : count)
            if (c == maxSize) ++res;
        return res;

    }
};