// 1963. Minimum Number of Swaps to Make the String Balanced

// Solution 1 using Greedy Approach
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int minSwaps(string s) {
        int res = 0, count = 0;
        for(char ch : s){
            // If the character is '[', increment the counter
            if(ch == '[') count++;
            // If the character is ']'
            else{
                // If the counter is greater than 0, decrement the counter
                if(count > 0) count--;
                // If the counter is 0, increment the result, because the string is unbalanced and ] is encountered before [
                else{
                    res++;
                    count++;
                }
            }
        }
        // Return the result
        return res;
    }
};
