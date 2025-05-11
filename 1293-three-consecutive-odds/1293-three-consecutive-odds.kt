class Solution {
    fun threeConsecutiveOdds(arr: IntArray): Boolean {
        var cnt = 0
        for (n in arr) {
            cnt = if (n % 2 == 1) cnt + 1 else 0
            if (cnt == 3) return true
        }
        return false
    }
}