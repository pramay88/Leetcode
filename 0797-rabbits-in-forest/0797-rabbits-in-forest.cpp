class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> hash;
        for(int ans: answers) hash[ans]++;
        int total = 0;
        for(auto x: hash){
            int ans = x.first, freq = x.second;
            int groupSize = ans + 1;
            int groups = ceil((double)freq / groupSize);
            total += groups * groupSize;
        }
        return total;
    }
};