class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int count = numBottles, empty = numBottles;
        while(empty >= numExchange){
            empty -= numExchange;
            count++, empty++;
            numExchange ++;
        }
        return count;
    }
};