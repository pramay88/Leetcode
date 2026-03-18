class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> a = asteroids;
        stack<int> st;

        for(int x: a){
            while(!st.empty() && st.top() > 0 && x < 0){
                if(st.top() < -x) st.pop();
                else if(st.top() == -x){ st.pop(); x = 0;}
                else x = 0;
            }
            if(x != 0) st.push(x);
        }

        vector<int> ans(st.size());
        for(int i = st.size() - 1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }
        
        return ans;
    }
};