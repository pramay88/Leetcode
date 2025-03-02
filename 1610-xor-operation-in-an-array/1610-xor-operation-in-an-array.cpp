class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> arr(n);
        for(int i=0; i<n;i++){
            arr[i] = start + 2 * i;
        }
        int x = 0;
        for(int num: arr){
            x ^= num;
        }
        return x;
    }
};