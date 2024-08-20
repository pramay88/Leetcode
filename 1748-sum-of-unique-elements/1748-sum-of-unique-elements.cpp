class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int count[101]{};
        for(int i: nums){
            ++count[i];
        }   
        int a=0;
        for(int j=0;j<101;j++){
            if(count[j]==1){
                a+=j;
            }
        }
        return a;
    }
};