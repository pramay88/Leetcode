class Solution {
    public int maxWidthRamp(int[] nums) {
        int len=nums.length;
        Deque<Integer> st = new ArrayDeque<>();
        for (int i = 0; i < len; ++i) {
            if (st.isEmpty() || nums[st.peek()] > nums[i]) {
                st.push(i);
            }
        }
        int res = 0;
        for (int i = len - 1; i >= 0; --i) {
            while (!st.isEmpty() && nums[st.peek()] <= nums[i]) {
                res = Math.max(res, i - st.pop());
            }
            if (st.isEmpty()) {
                break;
            }
        }
        return res;

    }
}