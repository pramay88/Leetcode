class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        long long minLandEnd = LLONG_MAX;
        for(int i = 0; i < landStartTime.size(); i++){
            minLandEnd = min(minLandEnd, (long long)landStartTime[i] + landDuration[i]);
        }

        long long minWaterEnd = LLONG_MAX;
        for(int j = 0; j < waterStartTime.size(); j++){
            minWaterEnd = min(minWaterEnd, (long long)waterStartTime[j] + waterDuration[j]);
        }

        long long ans = LLONG_MAX;

        // Land -> Water
        for(int j = 0; j < waterStartTime.size(); j++){
            ans = min(ans, max(minLandEnd, (long long)waterStartTime[j]) + waterDuration[j]);
        }

        // Water -> Land
        for(int i = 0; i < landStartTime.size(); i++){
            ans = min(ans, max(minWaterEnd, (long long)landStartTime[i]) + landDuration[i]);
        }

        return ans;
    }
};