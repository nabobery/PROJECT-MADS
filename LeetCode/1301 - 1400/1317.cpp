// 1317. Convert Integer to the Sum of Two No-Zero Integers

// Solution 1: Brute Force and Straightforward Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    bool isNoZero(int n){
        while(n){
            if(n%10 == 0) return false;
            n /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;
        for(int i = 1; i <= n/2;i++){
            if(isNoZero(i) && isNoZero(n-i)){
                res = {i, n-i};
                break;
            }
        }
        return res;
    }
};