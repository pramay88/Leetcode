class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> distinctSet(nums.begin(), nums.end());
        int totalDistinct = distinctSet.size();

        int l = 0, count = 0;
        unordered_map<int, int> hash;

        for (int r = 0; r < n; ++r) {
            hash[nums[r]]++;

            while (hash.size() == totalDistinct) {
                count += n - r;
                hash[nums[l]]--;
                if (hash[nums[l]] == 0)
                    hash.erase(nums[l]);
                l++;
            }
        }
        return count;
    }
};