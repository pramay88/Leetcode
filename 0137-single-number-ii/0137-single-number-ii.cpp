class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int num : nums) {
                if (num & (1 << i)) count++;
            }
            if (count % 3 != 0) {
                res |= (1 << i);
            }
        }
        if (res & (1 << 31)) {
            res -= (1LL << 32);
        }
        return res;
    }
};