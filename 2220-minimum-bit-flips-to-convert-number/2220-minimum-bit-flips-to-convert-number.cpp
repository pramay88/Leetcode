class Solution {
public:
    int minBitFlips(int start, int goal) {
       int xorr=start^goal;
       int count=0;
       while(xorr){
        count+=xorr & 1;
        xorr>>=1;
       }
       return count;
    }
};