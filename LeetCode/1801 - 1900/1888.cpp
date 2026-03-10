// 1888. Minimum Number of Flips to Make the Binary String Alternating

// Solution 1: Using Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int minFlips(string s) {
        string str = s+s, curr;
        // res0 is the number of flips needed to make the current window match the pattern "0101..."
        // res1 is the number of flips needed to make the current window match the pattern "1010..."
        int n = s.size(), res0 = 0, res1 = 0, res = n;
        // Calculate the number of flips needed for both patterns in the first window
        for(int i = 0; i < n;i++){
            if(i%2){
                if(str[i] == '0') res0++;
                else res1++;
            }
            else{
                if(str[i] == '1') res0++;
                else res1++; 
            }
        }
        // Update the result with the minimum flips for the first window
        res = min({res, res0, res1});
        for(int i = n; i < 2*n;i++){
            // Add the contribution of the new character entering the window
            if(i%2){
                if(str[i] == '0') res0++;
                else res1++;
            }
            else{
                if(str[i] == '1') res0++;
                else res1++; 
            }
            // Remove the contribution of the character leaving the window
            if((i-n)%2){
                if(str[i-n] == '0') res0--;
                else res1--;
            }
            else{
                if(str[i-n] == '1') res0--;
                else res1--; 
            }
            res = min({res, res0, res1});
        }
        return res;
    }
};

// Elegant Solution: Using Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int diff0 = 0, diff1 = 0;
        int res = n;

        // Iterate through the "virtual" doubled string
        for (int i = 0; i < 2 * n; ++i) {
            // 1. Add the current character's contribution
            // Pattern 0: s[i%n] should match i%2
            if ((s[i % n] - '0') != (i % 2)) diff0++;
            // Pattern 1: s[i%n] should match (i+1)%2
            else diff1++;

            // 2. Remove the character that just left the window
            if (i >= n) {
                int left = i - n;
                if ((s[left % n] - '0') != (left % 2)) diff0--;
                if ((s[left % n] - '0') != ((left + 1) % 2)) diff1--;
            }

            // 3. Update the result once the window is full
            if (i >= n - 1) {
                res = min({res, diff0, diff1});
            }
        }
        return res;
    }
};