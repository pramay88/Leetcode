public class Solution {
    public bool ThreeConsecutiveOdds(int[] arr) {
        int cnt = 0;
        foreach (int n in arr) {
            cnt = (n % 2 == 1) ? cnt + 1 : 0;
            if (cnt == 3) return true;
        }
        return false;
    }
}