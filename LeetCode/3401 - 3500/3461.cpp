// 3461. Check If Digits Are Equal in String After Operations I

// Solution 1: Simulation
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        string curr = s;
        for(int i = 0; i < n-2;i++){
            for(int j = 0; j < n-i-1;j++){
                curr[j] = ((curr[j] -'0' + curr[j+1] -'0')%10) + '0';
            }
        }
        return curr[0] == curr[1];
    }
};