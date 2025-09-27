class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if (numerator == 0) return "0";
        string res;

        if ((numerator < 0) ^ (denominator < 0)) res.push_back('-');

        long long n = llabs(numerator), d = llabs(denominator);
        res += to_string(n / d);
        long long remainder = n % d;

        if(remainder == 0) return res;

        res.push_back('.');
        unordered_map<long long, int> remainderHash;

        while(remainder) {
            if(remainderHash.count(remainder)) {
                res.insert(remainderHash[remainder], "(");
                res.push_back(')');
                break;
            }
            remainderHash[remainder] = res.size();
            remainder *= 10;
            res += to_string(remainder / d);
            remainder %= d;
        }
        return res;
    }
};