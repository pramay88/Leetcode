class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0, prev = 0;
        for(string &row : bank){
            const int ones = ranges::count(row, '1');
            if(ones > 0)
                res += prev * ones, prev = ones;
        }
        return res;
    }
};