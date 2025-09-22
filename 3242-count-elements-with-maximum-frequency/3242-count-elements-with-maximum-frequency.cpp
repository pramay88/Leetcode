class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        int maxFreq = 0, res = 0;
        for(int &n: nums){
            int f = ++freq[n];
            if(f > maxFreq) maxFreq = f, res = f;
            else if(f == maxFreq) res += f;
        }
        return res;
    }
};