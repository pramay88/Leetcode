class Solution {
    int f(vector<int> &nums, int left, int right){
        if (left == right) return nums[left];
        int prev1 = nums[left], next;
        int prev2 = max(nums[left], nums[left + 1]);
        for(int i = left + 2; i <= right; i++){
            next = max(
                prev2,
                nums[i] + prev1
            );
            prev1 = prev2;
            prev2 = next;
        }
        return next = prev2;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(f(nums, 0, n - 2), f(nums, 1, n - 1));
    }
};