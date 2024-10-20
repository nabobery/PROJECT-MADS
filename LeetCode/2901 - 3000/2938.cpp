// 2938. Separate Black and White Balls

// Solution 1 Greedy
// The idea is to calculate the number of white balls that have to go to the left and the number of black balls that have to go to the right. Then, we can calculate the number of swaps needed to move the white balls to the left and the black balls to the right.
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0, count = 0;
        // Iterate the string from right to left
        for(int i = s.size()-1; i >=0; i--){
            // If the character is '0', increment the counter
            // which represents the number of white balls that have to go to the left
            if(s[i] == '0') count++;
            // If the character is '1', increment the result by the counter
            else res += count;
        }
        return res;
    }
};
