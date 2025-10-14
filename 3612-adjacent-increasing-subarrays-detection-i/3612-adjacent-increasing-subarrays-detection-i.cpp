class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2 * k) return false;
        for(int a = 0; a + 2 * k <= n; a++){
            bool first = true, second = true;
            for(int i = a + 1; i < a + k; i++){
                if (nums[i] <= nums[i - 1]){
                    first = false;
                    break;
                }
            }
            if (!first) continue;
            for(int i = a + k + 1; i < a + 2 * k; i++){
                if(nums[i] <= nums[i - 1]){
                    second = false;
                    break;
                }
            }
            if(second) return true;
        }
        return false;
    }
};