class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int m = low + (high - low)/2;
            if(nums[m] == target) return true;
            
            if(nums[low] <= nums[m]){
                if(nums[low] <= target && target <= nums[m])
                    high--;
                else low++;
            }
            else{
                if(nums[m] <= target && target <= nums[high])
                    low++;
                else high--;
            }
        }
        return false;
    }
};