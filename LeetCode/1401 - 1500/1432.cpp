// 1432. Max Difference You Can Get From Changing an Integer

// Solution 1: Greedy Approach
// Time Complexity: O(1), since the number of digits in an integer is limited (at most 10 for 32-bit integers)
// Space Complexity: O(1), since we are using a constant amount of space
class Solution {
public:
    int maxDiff(int num) {
        string numStr = to_string(num);
        int mxd = 9, mid = 1;
        // Find the first minimum digit that can be changed to 9
        for(auto& ch : numStr){
            if(ch - '0' < mxd){
                mxd = ch - '0';
                break;
            }
        }
        // Find the first maximum digit that can be changed to 1 or 0
        for(auto& ch : numStr){
            if(ch - '0' > mid){
                mid = ch - '0';
                break;
            }
        }
        string mxStr = numStr, miStr = numStr;
        // to avoid leading zeros, we change the first digit to 1 or 0 depending on the digit
        char miCh = (mid == numStr[0] - '0')  ? '1' : '0';
        for(auto& ch : mxStr)
            if(ch - '0' == mxd) ch = '9';
        for(auto& ch : miStr)
            if(ch - '0' == mid) ch = miCh;
        // cout<<mxStr<<" "<<miStr<<"\n";
        int res = stoi(mxStr) - stoi(miStr);
        return res;
    }
};