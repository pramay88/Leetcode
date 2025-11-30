class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int rem=0;
        for(int i: nums) rem = (rem+i)%p;
        if(rem == 0) return 0;
        unordered_map<int,int> hash;
        hash[0] = -1;
        int len = nums.size(), ans = len, curr = 0;
        for(int i=0; i < len; ++i){
            curr = (curr + nums[i])%p;
            int target = (curr - rem + p) % p;
            if(hash.count(target)){
                ans = min(ans, i - hash[target]);
            }
            hash[curr] = i;
        }
        return ans == len? -1: ans;
    }
};