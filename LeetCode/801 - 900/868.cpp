// 868. Binary Gap

// Solution 1: Using BitSet
// Time Complexity: O(log n) where n is the input number
// Space Complexity: O(1)
class Solution {
public:
    int binaryGap(int n) {
        bitset<32> b(n);
        int prev = -1, res = 0;
        for(int i = 31; i >= 0;i--){
            if(b[i]){
                if(prev != -1) res = max(res, prev-i);
                prev = i;
            }
        }
        return res;
    }
};