// 2566. Maximum Difference by Remapping a Digit

// Solution 1: Greedy and Straightforward
// Time Complexity: O(1), since the number of digits in the integer is constant (at most 10 for 32-bit integers)
// Space Complexity: O(1) 
class Solution {
public:
    int minMaxDifference(int num) {
        string numStr = to_string(num);
        int mxd = 9, mid = numStr[0] - '0';
        for(auto& ch : numStr){
            if(ch - '0' < mxd){
                mxd = ch - '0';
                break;
            }
        }
        string mxStr = numStr, miStr = numStr;
        for(auto& ch : mxStr)
            if(ch - '0' == mxd) ch = '9';
        for(auto& ch : miStr)
            if(ch - '0' == mid) ch = '0';
        int res = stoi(mxStr) - stoi(miStr);
        return res;
    }
};