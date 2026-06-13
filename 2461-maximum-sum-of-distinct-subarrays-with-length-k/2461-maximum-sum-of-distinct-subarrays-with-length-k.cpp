class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long sum = 0;
        long long maxx = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            freq[nums[i]]++;
            
            if(i >= k){
                sum -= nums[i - k];
                freq[nums[i - k]]--;
                if(freq[nums[i - k]] == 0) freq.erase(nums[i - k]);
            }

            if(i >= k - 1 && freq.size() == k)
                maxx = max(maxx, sum);
        }
        return maxx;
    }
};