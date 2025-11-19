class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for(int n: nums)
            if(n == original)
                original *= 2;
        return original;
    }
};