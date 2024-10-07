class Solution {
public:
    int minLength(string s) {
        string stack = " ";
        for (char c : s) {
            if ((c == 'B' && stack.back() == 'A') || (c == 'D' && stack.back() == 'C')) {
                stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }
        return stack.size() - 1;
    }
};