// 761. Special Binary String

// Solution 1: Recursion + Sorting
// Time Complexity: O(n^2logn) where n is the length of the string
// Space Complexity: O(n) for the recursion stack
// Observations: 
// 1. A special binary string can be decomposed into smaller special binary strings. We can recursively find these substrings, sort them in descending order, and concatenate them to get the largest possible string.
// 2. The count of '1's and '0's must be equal in a special binary string, and at any point in the string, the count of '1's should not be less than the count of '0's.4
class Solution {
public:
    string makeLargestSpecial(string s) {
        int l = 0, n = s.size(), cnt = 0;
        // Vector to store the special substrings found in the input string
        vector<string> subs;
        // Iterate through the string to find special substrings
        for(int r = 0; r < n;r++){
            if(s[r] == '0') cnt--;
            else cnt++;
            // When cnt is 0, it means we have found a special substring from index l to r
            if(cnt == 0){
                // Recursively find the largest special substring within the current substring and add '1' and '0' to form the complete special substring
                subs.push_back("1" + makeLargestSpecial(s.substr(l+1, r-l-1)) + "0");
                // Move the left pointer to the next position after the current substring
                l = r+1;
            }
        }
        // Sort the substrings in descending order to get the largest possible string
        sort(subs.begin(), subs.end(), greater<>());
        string res;
        // Concatenate the sorted substrings to form the final result
        for(auto& str : subs) res += str;
        return res;
    }
}; 