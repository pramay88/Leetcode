class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(int n: nums){
            hash[n]++;
        }
        int n = nums.size();
        for(auto x: hash){
            if(x.second > n/2) return x.first;
        }
        return -1;
    }
};