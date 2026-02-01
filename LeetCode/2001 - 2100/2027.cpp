// 2027. Minimum Moves to Convert String

// Solution 1: Greedy and Straightforward
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int minimumMoves(string s) {
        int res = 0, n = s.size();
        for(int i = 0; i < n;i++){
            if(s[i] == 'X'){
                res++;
                i += 2;
            }
        }
        return res;
    }
};