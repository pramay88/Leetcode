class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = 0, even = 0;
        for(int i = 1; i <= n; i++){
            odd += (2 * i - 1);
            even += (2 * i);
        }
        
        int gcd = 1;
        for(int i = 1; i <= min(odd, even); i++){
            if(odd % i == 0 && even % i == 0)
                gcd = i;
        }

        return gcd;
    }
};