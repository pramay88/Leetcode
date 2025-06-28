class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> indexed;
        for (int i = 0; i < nums.size(); ++i) {
            indexed.push_back({nums[i], i});
        }
        sort(indexed.begin(), indexed.end(), greater<>());

        vector<pair<int, int>> topK(indexed.begin(), indexed.begin() + k);

        sort(topK.begin(), topK.end(), [](auto& a, auto& b) { return a.second < b.second; });

        vector<int> result;
        for (auto& p : topK) {
            result.push_back(p.first);
        }
        return result;
    }
};