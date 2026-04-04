// 2075. Decode the Slanted Ciphertext

// Solution 1: Simulation
// Time Complexity: O(n) where n is the length of encodedText
// Space Complexity: O(n) for the result string
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int sz = encodedText.size();
        // If the encoded text is empty, return an empty string
        if (sz == 0)
            return "";

        // Calculate the number of columns based on the length of the encoded text and the number of rows
        int cols = sz / rows;
        string res = "";

        // Simulate the decoding process by iterating through the columns and rows in a diagonal manner
        for (int j = 0; j < cols; j++) {
            // For each starting column, iterate through the rows to collect characters in a diagonal manner
            for (int i = 0; i < rows; i++) {
                // Calculate the current row and column based on the starting column and the current row index
                int currRow = i;
                int currCol = j + i;

                // If the current column is within bounds, append the character to the result string
                if (currCol < cols) {
                    res += encodedText[currRow * cols + currCol];
                // If the current column exceeds the number of columns, break out of the loop for the current starting column
                } else {
                    break;
                }
            }
        }

        // Remove trailing spaces from the result string
        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }
        // Return the decoded string
        return res;
    }
};