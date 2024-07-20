// 1518. Water Bottles

// Solution 1: Simulation
// Time complexity: O(log(numBottles))
// Space complexity: O(1)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles, empty = numBottles;
        while(empty/numExchange){
            res += empty/numExchange;
            empty = empty/numExchange + empty%numExchange;
        }
        return res;
    }
};

// Solution 2: Math
// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};
