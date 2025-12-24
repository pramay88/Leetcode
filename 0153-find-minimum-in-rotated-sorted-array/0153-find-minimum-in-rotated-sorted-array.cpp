class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, m;
        while(low < high){
            m = low + (high - low)/2;
            if(nums[m] < nums[high]){
                high = m;
            }
            else low = m + 1;
        }
        return nums[low];
    }
};