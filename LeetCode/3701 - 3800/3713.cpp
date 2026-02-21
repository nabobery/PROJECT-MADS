// 3713. Longest Balanced Substring I

// Solution 1: Brute Force using Sliding Window 
// Time Complexity: O(n^2) 
// Space Complexity: O(1)
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size(), res = 0;
        for(int i = 0; i < n;i++){
            // To count the frequency of each character in the current window
            vector<int> cnt(26, 0);
            for(int j = i; j < n;j++){
                // Increment the count of the current character
                cnt[s[j] - 'a']++;
                bool b = true;
                // Check if all non-zero counts are the same
                for(auto& c : cnt){
                    if(c > 0 && c != cnt[s[j] - 'a']){
                        b = false;
                        break;
                    }
                }
                // If all non-zero counts are the same, update the result
                if(b) res = max(res, j-i+1);
            }
        }
        // Return the length of the longest balanced substring
        return res;
    }
};