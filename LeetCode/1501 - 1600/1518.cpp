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
// Each exchange uses k empties and after drinking the new bottle returns 1 empty,
// so net empties drop by (k-1) per exchange. Starting empties = B.
// Max exchanges E satisfies B - E*(k-1) < k <=> B − (E − 1)(k − 1) >= k, which gives
// E = floor((B - 1) / (k - 1)). Total drunk = B + E.
// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};
