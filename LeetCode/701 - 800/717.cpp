// 717. 1-bit and 2-bit Characters

// Solution 1: Simple and Straightforward
// Explanation: Just check if the last character is a 1-bit character by simulating the parsing of the bits.
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if(n == 1) return true;
        for(int i = 0; i < n;i++){
            if(i == n-1) return true;
            if(bits[i]) i++;
        }
        return false;
    }
}; 