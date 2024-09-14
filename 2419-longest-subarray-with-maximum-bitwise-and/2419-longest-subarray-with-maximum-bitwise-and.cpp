class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int num=*max_element(nums.begin(),nums.end());
        int ans=1;
        int curr=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1] && nums[i]==num){
                curr++;
                ans=max(curr,ans);
            }
            else curr=1;
        }
        return ans;
    }
};