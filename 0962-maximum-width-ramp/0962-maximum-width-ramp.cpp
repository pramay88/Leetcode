class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int len = nums.size();
        stack<int> st;
        for (int i = 0; i < len; ++i) {
            if (st.empty() || nums[st.top()] > nums[i]) st.push(i);
        }
        int res = 0;
        for (int i = len - 1; i; --i) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                res = max(res, i - st.top());
                st.pop();
            }
            if (st.empty()) break;
        }
        return res;
    }
};