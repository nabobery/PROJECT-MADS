// 1513. Number of Substrings With Only 1s

// Solution 1: Simple Counting and Math
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    const int mod = 1e9+7;
    int numSub(string s) {
        long res = 0, curr = 0;
        for(auto& ch: s){
            if(ch == '0') curr = 0;
            else{
                curr++;
                res = (res+curr)%mod;
            }
        }
        return res;
    }
};