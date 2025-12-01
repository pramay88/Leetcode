class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        while(x != 0){
            int rem = x % 10;
            rev = rev * 10 + rem;
            x /= 10;
        }
        return (rev > INT_MAX || rev < INT_MIN)? 0: rev;
    }
};