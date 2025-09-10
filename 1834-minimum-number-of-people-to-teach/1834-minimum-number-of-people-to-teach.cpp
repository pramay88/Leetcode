class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int> problematic;
        for (auto &f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            for (int langU : languages[u - 1]) {
                for (int langV : languages[v - 1]) {
                    if (langU == langV){
                        canCommunicate = true;
                        break;
                    }
                }
                if (canCommunicate) break;
            }
            if (!canCommunicate)
                problematic.insert(u), problematic.insert(v);
        }

        if (problematic.empty()) return 0;

        unordered_map<int,int> langCount;
        for (int user : problematic) {
            for(int lang : languages[user - 1])
                langCount[lang]++;
        }
        int maxlangCount = 0;
        for (auto &x : langCount) {
            maxlangCount = max(maxlangCount, x.second);
        }
        return (int)problematic.size() - maxlangCount;
    }
};