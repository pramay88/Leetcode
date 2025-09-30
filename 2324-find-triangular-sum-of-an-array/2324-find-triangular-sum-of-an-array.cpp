class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1   ) return nums[0];
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < i; j++){
                nums[j] = (nums[j] + nums[j+1]) % 10;
            }
            if(--n == 1) return nums[0];
        }
        return 0;
    }
};