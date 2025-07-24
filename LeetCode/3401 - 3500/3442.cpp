// 3442. Maximum Difference Between Even and Odd Frequency I

// Solution 1: Straightforward and Greedy Approach
// Time Complexity: O(n), where n is the length of the input string
// Space Complexity: O(1), since we only use a fixed number of variables
class Solution {
public:
    int maxDifference(string s) {
        vector<int> cnt (26, 0);
        int n = s.size();
        for(char& ch : s) cnt[ch - 'a']++;
        int mxOdd = 0, miEven = n;
        for(int& c: cnt){
            if(c){
                if(c%2) mxOdd = max(mxOdd, c);
                else miEven = min(miEven, c);
            }
        }
        return mxOdd - miEven;
    }
};