// 3227. Vowels Game in a String

// Solution 1: Greedy and StraightForward
// Time Complexity: O(n)
// Space Complexity: O(1)
// if number of vowels is odd, alice always wins
// else 
// (if no vowels) return false
// else alice can take vowels-1 and win
class Solution {
public:
    bool doesAliceWin(string s) {
        int vowels = 0;
        for(char& ch : s)
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') vowels++;
        if(vowels == 0) return false;
        return true;
    }
};

