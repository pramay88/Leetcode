class Solution {
public:
    int totalMoney(int n) {
        int money = 0, week = 0;
        for(int i = 1; i <= n; i++){
            money += (i - 1) % 7 + 1 + week;
            if(i % 7 == 0) week++;
        }
        return money;
    }
};