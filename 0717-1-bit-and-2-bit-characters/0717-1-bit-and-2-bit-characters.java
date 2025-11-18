class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int x = 0, n = bits.length;
        while(x < n - 1){
            x += bits[x] + 1;
        }
        return x == n - 1;
    }
}