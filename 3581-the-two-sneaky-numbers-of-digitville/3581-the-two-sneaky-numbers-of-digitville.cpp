class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> hash;
        for(int x: nums){
            ++hash[x];
            if(hash[x] == 2) res.push_back(x);
        }
        return res;
    }
};