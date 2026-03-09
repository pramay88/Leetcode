class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size(), prev = 1;
        unordered_map<int, int> mp;
        vector<int> ans;

        for(int x: nums) mp[x]++;

        for(int i = 1; i <= n; i++){
            if(mp.find(i) == mp.end())
                ans.push_back(i);
        }

        return ans;
    }
};