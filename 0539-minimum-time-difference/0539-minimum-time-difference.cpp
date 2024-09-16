class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() > 1440) {
            return 0;
        }
        int n=timePoints.size();
        vector<int> minutes(n);
        for(int i=0;i<n;i++){
            int h=stoi(timePoints[i].substr(0,2));
            int m=stoi(timePoints[i].substr(3,2));
            minutes[i]=h*60+m;
        }
        sort(minutes.begin(),minutes.end());
        if(minutes[0]==minutes[1])  return 0;
        int res=INT_MAX;
        for(int i=1;i<n;i++)
            res=min(res,minutes[i]-minutes[i-1]);

        return min(res,1440-(minutes.back()-minutes.front()));
    }
};