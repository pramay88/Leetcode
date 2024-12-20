class Solution {
    fun maxChunksToSorted(arr: IntArray): Int {
        var maxSoFar = 0 
        var chunks = 0   
        for (i in arr.indices) {
            maxSoFar = maxOf(maxSoFar, arr[i]) 
            if (maxSoFar == i) {              
                chunks++
            }
        }
        return chunks
    }
}