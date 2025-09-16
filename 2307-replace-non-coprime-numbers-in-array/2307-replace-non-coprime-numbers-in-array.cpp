class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        for (int x : nums) {
            res.push_back(x);
            while (res.size() > 1) {
                int a = res[res.size() - 2];
                int b = res[res.size() - 1];
                int g = std::gcd(a, b);
                if (g == 1) break;
                long long lcm = 1LL * a * b / g;
                res.pop_back();
                res.pop_back();
                res.push_back((int)lcm);
            }
        }
        return res;
    }
};