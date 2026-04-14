// 1320. Minimum Distance to Type a Word Using Two Fingers

// Solution 1: Using Dynamic Programming 3D
// Time Complexity: O(n * 27 * 27)
// Space Complexity: O(n * 27 * 27)
class Solution {
public:
    // Helper function to calculate the distance between two characters on the keyboard
    int dist(int curr, int next) {
        if (curr == -1)
            return 0;
        int cr = curr / 6, cc = curr % 6, nr = next / 6, nc = next % 6;
        return abs(cr - nr) + abs(cc - nc);
    }
    int minimumDistance(string word) {
        int n = word.size(), res = INT_MAX;
        // dp[i][j][k] represents the minimum distance to type the substring starting from index i
        // with the first finger on character j and the second finger on character k
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(27, vector<int>(27, 1e6)));
        // traverse the word from the end to the beginning
        for (int i = n - 1; i >= 0; i--) {
            int currChar = word[i] - 'A';
            for (int j = 0; j < 27; j++) {
                for (int k = 0; k < 27; k++) {
                    int moveCurrCharToFinger1, moveCurrCharToFinger2;
                    // base case: If it's the last character, we don't need to move the fingers 
                    if (i == n - 1) {
                        moveCurrCharToFinger1 = 0;
                        moveCurrCharToFinger2 = 0;
                    // else we calculate the cost of moving the current character to either finger 1 or finger 2 to current Char
                    } else {
                        moveCurrCharToFinger1 = dp[i + 1][currChar + 1][k];
                        moveCurrCharToFinger2 = dp[i + 1][j][currChar + 1];
                    }
                    // Calculate the minimum distance to type the current character with either finger
                    dp[i][j][k] =
                        min(dist(j - 1, currChar) + moveCurrCharToFinger1,
                            dist(k - 1, currChar) + moveCurrCharToFinger2);
                    // If it's the first character, we update the result with the minimum distance found
                    if(i == 0) res = min(res, dp[i][j][k]);
                }
            }
        }
        // Return the minimum distance to type the entire word
        return res;
    }
};

// Solution 2: Using Dynamic Programming 1D (Time and Space Optimized)
// The idea is we know that one finger will always be on the last character typed, so we can optimize the DP to only keep track of the other finger's position and the current index in the word.
// Time Complexity: O(n * 27)
// Space Complexity: O(27) = O(1)
class Solution {
public:
    // Helper function to calculate the distance between two characters on the keyboard
    int dist(int a, int b) {
        if (a == -1)
            return 0;
        int r1 = a / 6, c1 = a % 6;
        int r2 = b / 6, c2 = b % 6;
        return abs(r1 - r2) + abs(c1 - c2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        // dp[j] represents the minimum distance to type the substring starting from index i with the other finger on character j
        vector<int> dp(27, 1e9);
        // base case: If it's the last character, we don't need to move the fingers
        dp[26] = 0;

        // Traverse the word character by character
        for (int i = 0; i < n; i++) {
            // newdp will store the minimum distance for the current character with the other finger on character j
            vector<int> newdp(27, 1e9);
            int curr = word[i] - 'A';

            // For each possible position of the other finger, we calculate the cost of moving the current character to either finger 1 or finger 2 and update the newdp accordingly
            for (int other = 0; other <= 26; other++) {
                // If the distance for the other finger is still at the initial value, we skip it as it means it's not a valid state
                if (dp[other] == 1e9)
                    continue;

                // cost of moving the finger which is currently on the last character typed to the current character
                // if its not the first character, we also consider the cost of moving the other finger to the current character
                if (i > 0) {
                    int prev = word[i - 1] - 'A';
                    newdp[other] =
                        min(newdp[other], dp[other] + dist(prev, curr));
                // if it's the first character, we consider the cost of moving the other finger from the initial position to the current character
                } else {
                    newdp[other] = min(newdp[other], dp[other]);
                }

                // cost of moving the other finger to the current character
                // if it's not the first character, we also consider the cost of moving the finger which is currently on the last character typed to the current character
                if (i > 0) {
                    int prev = word[i - 1] - 'A';
                    newdp[prev] =
                        min(newdp[prev],
                            dp[other] + dist(other == 26 ? -1 : other, curr));
                // if it's the first character, we consider the cost of moving the finger which is currently on the last character typed to the current character
                } else {
                    newdp[26] = min(newdp[26], dp[other] + dist(-1, curr));
                }
            }
            // Update dp to newdp for the next iteration
            dp = newdp;
        }
        // Return the minimum distance to type the entire word, which is the minimum value in dp
        return *min_element(dp.begin(), dp.end());
    }
};