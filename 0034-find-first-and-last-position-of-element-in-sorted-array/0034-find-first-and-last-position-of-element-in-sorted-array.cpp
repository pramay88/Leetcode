class Solution {
    int bs(vector<int> &nums, int target, bool searchingLeft){
        int low = 0, high = nums.size() - 1, idx = -1;
        
        while(low <= high){
            int m = low + (high - low)/2;
            if(nums[m] < target) low = m + 1;
            else if(nums[m] > target) high = m - 1;
            else{
                idx = m;
                if(searchingLeft) high = m - 1;
                else low = m + 1;
            }
        }
        return idx;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = bs(nums, target, true), right = bs(nums, target, false);
        return {left, right}; 
    }
};