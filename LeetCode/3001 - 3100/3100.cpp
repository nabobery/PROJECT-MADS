// 3100. Water Bottles II

// Solution 1: Using Simulation
// Time Complexity: O(numBottles)
// Space Complexity: O(1)
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles, empty = numBottles;
        while(empty >= numExchange){
            empty -= (numExchange - 1);          
            res++;
            numExchange++;
        }
        return res;
    }
};
