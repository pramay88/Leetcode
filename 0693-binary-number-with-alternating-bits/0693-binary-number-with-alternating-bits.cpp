class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n > 0){
            if((n & 1) == ((n >> 1) & 1))   // if current bit and next bit are same
                return false;
            n >>= 1;
        }
        return true;
    }
};