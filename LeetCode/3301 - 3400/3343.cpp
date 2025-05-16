// 3343. Count Number of Balanced Permutations

// Solution 1 using Math, Combinatorics, and Digit Dynamic Programming
// Time Complexity: O(n^2S) where n is the number of digits and S is the sum of digits
// Space Complexity: O(n^2 + nS) where n is the number of digits and S is the target sum
class Solution {
public:
    long long MOD = 1e9 + 7;
    int countBalancedPermutations(string num) {
        int sum = 0, n = num.size();
        vector<int> digitsCnt(10, 0);
        for (char& ch : num) {
            sum += (ch - '0');
            digitsCnt[ch - '0']++;
        }
        if (sum % 2)
            return 0;
        int target = sum / 2;
        int maxOdd = (n + 1) / 2;
        vector<vector<long long>> comb(maxOdd + 1,
                                       vector<long long>(maxOdd + 1));
        vector<vector<long long>> dp(target + 1, vector<long long>(maxOdd + 1));
        for (int i = 0; i <= maxOdd; i++) {
            comb[i][i] = comb[i][0] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }

        dp[0][0] = 1;
        int prefixSumDigits = 0, currSum = 0;
        for (int i = 0; i <= 9; i++) {
            prefixSumDigits += digitsCnt[i];
            currSum += (i * digitsCnt[i]);
            for (int oddCnt = min(prefixSumDigits, maxOdd);
                 oddCnt >= max(0, prefixSumDigits - (n - maxOdd)); oddCnt--) {
                int evenCnt = prefixSumDigits - oddCnt;
                for (int curr = min(currSum, target);
                     curr >= max(0, currSum - target); curr--) {
                    long long res = 0;
                    for (int j = max(0, digitsCnt[i] - evenCnt);
                         j <= min(digitsCnt[i], oddCnt) && i * j <= curr; j++) {
                        long long ways =
                            comb[oddCnt][j] * comb[evenCnt][digitsCnt[i] - j] % MOD;
                        res =
                            (res + ways * dp[curr - i * j][oddCnt - j] % MOD) %
                            MOD;
                    }
                    dp[curr][oddCnt] = res % MOD;
                }
            }
        }
        return dp[target][maxOdd];
    }
};