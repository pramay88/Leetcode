class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';
        
        int mid = 1 << (n - 1);
        
        if(k == mid) return '1';

        else if(k < mid)
            return findKthBit(n - 1, k);
 
        else{
            int mirrored = mid - (k - mid);
            char bit = findKthBit(n - 1, mirrored);
            return (bit == '0') ? '1' : '0';
        }
    }
};