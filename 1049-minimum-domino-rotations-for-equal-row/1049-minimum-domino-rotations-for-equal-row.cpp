class Solution {
public:
    int countMinRotations(int x, vector<int>& tops, vector<int>& bottoms, int size) {
        int topCnt = 0, bottomCnt = 0;
        for (int i = 0; i < size; ++i) {
            if (tops[i] != x && bottoms[i] != x) {
                return size + 1;
            }
            topCnt += tops[i] == x;
            bottomCnt += bottoms[i] == x;
        }
        return size - max(topCnt, bottomCnt);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {   
        int size = tops.size();
        int rotationsTop = countMinRotations(tops[0], tops, bottoms, size);
        int rotationsBottom = countMinRotations(bottoms[0], tops, bottoms, size);
        int minRotations = min(rotationsTop, rotationsBottom);

        return minRotations > size ? -1 : minRotations;
    }
};