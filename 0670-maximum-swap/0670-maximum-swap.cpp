class Solution {
public:
    int maximumSwap(int num) {
    string numStr = to_string(num);
    int n = numStr.size();
    char maxElement = numStr[n - 1];
    int maxIndex = n - 1;
    int Idx1 = -1;
    int Idx2 = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (numStr[i] > maxElement) {
            maxElement = numStr[i];
            maxIndex = i;
        } else if (numStr[i] < maxElement) {
            Idx1 = i;
            Idx2 = maxIndex;
        }
    }
    if (Idx1 != -1) {
        std::swap(numStr[Idx1], numStr[Idx2]);
    }
    return std::stoi(numStr);
    }
};