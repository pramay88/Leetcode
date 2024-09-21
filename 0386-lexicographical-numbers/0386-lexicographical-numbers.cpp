class Solution {
public:
    vector<int> vec;
    void dfs(int curr, int n) {
        if (curr > n) return; 
        vec.push_back(curr); 
        for (int i = 0; i < 10; ++i) { 
            int next = curr * 10 + i; 
            if (next > n) break; 
            dfs(next, n); 
        }
    }
    vector<int> lexicalOrder(int n) {
        if(n==0) return {};
        for (int i = 1; i <= 9; ++i) { 
            if (i > n) break; 
            dfs(i, n);
        }
        return vec;
    }
};