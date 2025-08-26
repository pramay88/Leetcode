class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size(), m = dimensions[0].size();
        int longestSq = INT_MIN, x = 0, area = 0, y = 0;
        for(int i=0; i<n; i++){
            int length = dimensions[i][0], width = dimensions[i][1];
            if(length*length + width*width > longestSq){
                longestSq = length*length + width*width;
                x = width, y =length;
                area = x*y;
            }
            else if(length*length + width*width == longestSq)
                area = max(area, length*width);
        }
        return area;
    }
};