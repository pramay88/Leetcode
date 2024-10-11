class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<int, vector<int>, greater<int>> q;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> occ;
        int n = times.size();
        for (int i = 0; i < n; ++i) {
            times[i].push_back(i);
            q.push(i);
        }
        sort(times.begin(), times.end());
        for (auto& t : times) {
            int a = t[0], b = t[1], i = t[2];
            while (!occ.empty() && occ.top().first <= a) {
                q.push(occ.top().second);
                occ.pop();
            }
            int c = q.top();
            q.pop();
            if (i == targetFriend) return c;
            occ.push({b, c});
        }
        return -1;
    }
};