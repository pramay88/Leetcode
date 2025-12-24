class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = high + 1;
        while(low <= high){
            int m = low + (high - low)/2;
            if(nums[m] >= target){
                high = m - 1;
                ans = m;
            }
            else low = m + 1;
        }
        return ans;
    }
};