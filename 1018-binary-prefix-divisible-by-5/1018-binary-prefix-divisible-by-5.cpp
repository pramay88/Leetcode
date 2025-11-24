class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int n = 0;
        for(int bit : nums){
            n = (n * 2 + bit) % 5;
            res.push_back(n == 0);
        }
        return res;
    }
};