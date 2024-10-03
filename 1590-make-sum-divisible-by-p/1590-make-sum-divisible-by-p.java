class Solution {
    public int minSubarray(int[] nums, int p) {
        int rem = 0;
        for (int num : nums) {
            rem = (rem + num) % p;
        }
        if (rem == 0) {
            return 0;
        }

        HashMap<Integer, Integer> hash = new HashMap<>();
        hash.put(0, -1);  
        int len = nums.length;
        int ans = len;
        int curr = 0;

        for (int i = 0; i < len; i++) {
            curr = (curr + nums[i]) % p;
            int target = (curr - rem + p) % p;

            if (hash.containsKey(target)) {
                ans = Math.min(ans, i - hash.get(target));
            }
            hash.put(curr, i);
        }

        return ans == len ? -1 : ans;
    }
}