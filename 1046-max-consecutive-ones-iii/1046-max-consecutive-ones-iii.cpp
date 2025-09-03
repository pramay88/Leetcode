class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0, longest = 0;
        int left = 0, n = nums.size();
        for(int right = 0; right < n; right++){
            if(nums[right] == 0) zeros++;
            if(zeros > k){
                if(nums[left] == 0) zeros--;
                left++;
            }
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};