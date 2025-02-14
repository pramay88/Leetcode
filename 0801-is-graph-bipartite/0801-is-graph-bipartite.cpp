class Solution {
    bool check(int node, vector<vector<int>> &adj, vector<int> &color){
        int m = adj.size();
        queue<int> q;
        q.push(node);
        color[node] = 0; 

        while(!q.empty()){
            int x = q.front(); 
            q.pop();
            for(int adjNode: adj[x]){
                if(color[adjNode] == -1){
                    color[adjNode] = 1 - color[x];
                    q.push(adjNode);
                }
                else if(color[adjNode] == color[x]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(!check(i, graph, color)) return false;
            }
        }
        return true;
    }
};