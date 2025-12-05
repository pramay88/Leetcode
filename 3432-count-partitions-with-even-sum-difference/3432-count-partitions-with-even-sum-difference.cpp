class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int count = 0, n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        
        for(int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        
        if(prefixSum[n - 1] % 2 != 0) return 0;
        
        for(int i = 0; i < n - 1; i++){
            if((prefixSum[n - 1] - 2 * prefixSum[i]) % 2 == 0)
                count++;
        }
        return count;
    }
};