class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int leftSum = 0, rightSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<int> sum(n, 0);

        for(int i = 0; i < n; i++){
            rightSum -= nums[i];
            sum[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }
        
        return sum;
    }
};