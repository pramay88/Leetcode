class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int num = 1; 
        for (int i = 0; i < n; i++) {
            result.push_back(num); 
            
            if (num * 10 <= n) {
                num *= 10; 
            } 
            else {
                
                if (num >= n) {
                    num /= 10; 
                }
                num++; 
                while (num % 10 == 0) {
                    num /= 10; 
                }
            }
        }

        return result;
    }
};