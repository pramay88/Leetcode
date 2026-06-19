class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int proviences = 0;

        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            proviences++;

            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while(!q.empty()){
                int city = q.front();
                q.pop();

                for(int next = 0; next < n; next++){
                    if(isConnected[city][next] && !vis[next]){
                        vis[next] = 1;
                        q.push(next);
                    }
                }
            }
        }
        
        return proviences;
    }
};