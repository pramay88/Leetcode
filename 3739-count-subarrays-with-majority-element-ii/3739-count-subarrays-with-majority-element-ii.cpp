class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size(), cnt = n;
        vector<int> pref(n * 2 + 1, 0);
        pref[n] = 1;
        long long ans = 0, prefsum = 0;

        for(int i = 0; i < n; ++i){
            if(nums[i] == target){
                prefsum += pref[cnt];
                cnt++;
                pref[cnt]++;
            }
            else{
                cnt--;
                prefsum -= pref[cnt];
                pref[cnt]++;
            }
            ans += prefsum;
        }
        
        return ans;
    }
};