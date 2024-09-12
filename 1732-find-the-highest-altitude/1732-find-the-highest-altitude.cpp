class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt=0;
        int highest=0;
        for(int i=0;i<gain.size();i++){
            alt+=gain[i];
            if(alt>=highest)    highest=alt;
        }
        return highest;
    }
};