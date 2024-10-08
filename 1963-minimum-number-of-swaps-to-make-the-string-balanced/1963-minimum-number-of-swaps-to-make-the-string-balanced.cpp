class Solution {
public:
    int minSwaps(string s) {
        int count = 0;
        for (char& c : s) {
            if (c == '[') {
                ++count;
            } else if (count) {
                --count;
            }
        }
        return (count + 1) / 2;
    }
    
};