class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int len = skill.size();
        int teams = len / 2;
        int totalSum = 0;
        unordered_map<int, int> freqMap;

        for(int element : skill) {
            freqMap[element]++;
            totalSum += element;
        }

        if (totalSum % teams != 0) {
            return -1;
        }

        int targetPoints = totalSum / teams;
        long long res = 0;

        for (int element : skill) {
            if (freqMap[element] == 0) {
                continue;
            }

            freqMap[element]--;
            int partner = targetPoints - element;

            if (freqMap[partner] == 0) {
                return -1;
            }

            freqMap[partner]--;
            res += static_cast<long long>(element) * static_cast<long long>(partner);
        }

        return res;

    }
};