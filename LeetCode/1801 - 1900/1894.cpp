// 1894. Find the Student that Will Replace the Chalk

// Solution 1: Straightforward Approach Simulation
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum = 0;
        for(int ch : chalk) sum += ch;
        if(k >= sum) k %= sum;
        for(int i = 0; i < chalk.size();i++){
            if(chalk[i] > k) return i;
            k -= chalk[i];
        }
        return -1;
    }
};