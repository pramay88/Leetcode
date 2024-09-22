class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size();
        vector<int> ans;
        int count=0;
        int totalCount=rows*cols;

        int sR=0,sC=0;
        int eR=rows-1,eC=cols-1;

        while(count<totalCount){

            // starting row
            for(int i=sC; count<totalCount && i<=eC;i++){
                ans.push_back(matrix[sR][i]);
                count++;
            }
            sR++;

            // ending column
            for(int i=sR; count<totalCount && i<=eR;i++){
                ans.push_back(matrix[i][eC]);
                count++;
            }
            eC--;

            // ending row
            for(int i=eC; count<totalCount && i>=sC; i--){
                ans.push_back(matrix[eR][i]);
                count++;
            }
            eR--;
            //starting column
            for(int i=eR; count<totalCount && i>=sR; i--){
                ans.push_back(matrix[i][sC]);
                count++;
            }
            sC++;
        }
        return ans;
    }
};