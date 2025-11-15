// 3228. Maximum Number of Operations to Move Ones to the End

// Solution 1: Greedy Counting and State Tracking
// Time Complexity: O(n)
// Space Complexity: O(1)

// The observation is that 0 acts as a barrier that allows all preceding 1s to be moved to the end and takes onesCount operations.
// The minimum way would be to club all 1s from the right instead of start to reduce redundant operations.
// The maximum way would be to start from the left and every time we encounter a 0, we can move all preceding 1s to the end.
class Solution {
public:
    int maxOperations(string s) {
        int res = 0, onesCount = 0, n = s.size();
        bool lastWasOne = false;
        for(int i = 0; i < n;i++){
            if(s[i] == '1'){
                onesCount++;
                lastWasOne = true;
            }
            else {
                if(lastWasOne) res += onesCount;
                lastWasOne = false;
            }
        }
        return res;
    }
};