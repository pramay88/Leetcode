class Solution {
public:
    vector<int> parent, rank;

    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y){
        int px = find(x), py = find(y);
        if (px == py) return;

        if (rank[px] < rank[py])
            parent[px] = py;

        else if(rank[px] > rank[py])
            parent[py] = px;
        
        else{
            parent[py] = px;
            rank[px]++;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++) parent[i] = i;

        for(auto &e : allowedSwaps) unite(e[0], e[1]);

        unordered_map<int, vector<int>> groups;
        for(int i = 0; i < n; i++)
            groups[find(i)].push_back(i);

        int ans = 0;

        for(auto &g : groups){
            unordered_map<int, int> freq;

            for(int idx : g.second)
                freq[source[idx]]++;

            for(int idx : g.second){
                if(freq[target[idx]] > 0)
                    freq[target[idx]]--;
                else ans++;
            }
        }

        return ans;
    }
};