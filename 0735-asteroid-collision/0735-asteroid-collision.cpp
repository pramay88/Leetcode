class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> v = asteroids;
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(v[i] < 0){
                int j = i - 1;
                int curr = abs(v[i]);
                while(j >= 0){
                    if(v[j] == 0){ j--; continue; }  // skip dead
                    if(v[j] < 0) break; // same direction
                    if(abs(v[j]) < curr){
                        v[j] = 0;
                        j--;
                    }
                    else if(abs(v[j]) == curr){
                        v[j] = 0;
                        v[i] = 0;
                        break;
                    }
                    else{
                        v[i] = 0;
                        break;
                    }
                }
            }
        }

        for(int i: v)
            if(i != 0) ans.push_back(i);
            
        return ans;
    }
};