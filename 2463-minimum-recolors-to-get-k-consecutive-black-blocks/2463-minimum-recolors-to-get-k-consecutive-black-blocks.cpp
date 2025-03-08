class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int white = 0;
        
        // Count whites in the first window of size k
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') white++; 
        }

        int count = white;

        // Sliding window: Shift the window one step at a time
        for (int i = k; i < n; i++) {
            if (blocks[i] == 'W') white++;
            if (blocks[i - k] == 'W') white--;
            count = min(count, white);
        }

        return count;

    }
};