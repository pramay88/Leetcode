class Solution {
    int f(int n) {
        vector<int> digits;
        while(n){
            digits.push_back(n % 10);
            n /= 10;
        }

        if(digits.size() < 3) return 0;

        int count = 0;
        for(int i = 1; i < digits.size() - 1; i++){
            if ((digits[i] > digits[i - 1] && digits[i] > digits[i + 1]) ||
                (digits[i] < digits[i - 1] && digits[i] < digits[i + 1])) {
                count++;
            }
        }

        return count;
    }

public:
    int totalWaviness(int num1, int num2) {
        int wavi = 0;

        for(int i = num1; i <= num2; i++){
            wavi += f(i);
        }

        return wavi;
    }
};