// 2311. Longest Binary Subsequence Less Than or Equal to K

// Solution 1: Greedy Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int res = 0, n = s.size(), curr = 0;
        // traverse the string from right to left
        for(int i = n-1; i >= 0;i--){
            // take all the zeroes
            if(s[i] == '0') res++;
            // take one only if possible (<= k)
            else{
                // doesn't make sense to take 1 if res >= 31 because k <= 10^9
                if(res >= 31) continue;
                int temp = pow(2, res);
                if(temp + curr <= k){
                    res++;
                    curr = curr + temp;
                } 
            }
        }
        return res;
    }
};