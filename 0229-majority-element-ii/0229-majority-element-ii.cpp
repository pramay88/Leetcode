class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int,int> hash;
        vector<int> res;
        for(int n: nums) hash[n]++;
        for(auto x: hash){
            if(x.second > len/3) res.push_back(x.first);
        }
        return res;
    }
};