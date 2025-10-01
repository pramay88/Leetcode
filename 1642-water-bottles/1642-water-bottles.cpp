class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = numBottles, empty = numBottles;
        while(empty >= numExchange){
            int exchange = empty/numExchange;
            empty += exchange - exchange*numExchange;
            count += exchange;
        }
        return count;
    }
};