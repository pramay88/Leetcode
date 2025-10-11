class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        if (power.empty()) return 0;
        map<int, int> freq;

        for(int p : power) freq[p]++;
        int prev1 = 0, prev2 = 0, lastPower = INT_MIN;

        for(auto& kv : freq){
            int p = kv.first;
            long long diff = (long long)p - (long long)lastPower;
            int total = p * kv.second, curr;

            if(diff <= 2)curr = max(prev1, prev2 + total);
            else curr = prev1 + total;
            prev2 = prev1;
            prev1 = curr;
            lastPower = p;
        }
        return prev1;
    }
};