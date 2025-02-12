class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        queue<int> q;
        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                q.push(i);
                vis[i] = 1;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (int adjNode : adj[node]) {
                        if (!vis[adjNode]) {
                            vis[adjNode] = 1;
                            q.push(adjNode);
                        }
                    }
                }
                provinces++;
            }
        }
        return provinces;
    }
};