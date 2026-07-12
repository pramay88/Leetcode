class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        vector<int> sortedArr {arr};
        sort(sortedArr.begin(), sortedArr.end());

        int rank = 1;
        unordered_map<int, int> rankMap;
        vector<int> res(n, 0);
        
        for(int x : sortedArr){
            if(!rankMap.count(x))
                rankMap[x] = rank++;
        }

        for(int i = 0; i < n; i++){
            res[i] = rankMap[arr[i]];
        }

        return res;
    }
};