// 564. Find the Closest Palindrome

// Solution 1 using math 
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string nearestPalindromic(string n) {
        int sz = n.size();
        set<long long> candidates;

        // Edge case: if n is "1", the closest palindrome is "0"
        if (n == "1") return "0";

        // Generate candidate palindromes
        candidates.insert(pow(10, sz) + 1); // e.g., 1000 -> 1001
        candidates.insert(pow(10, sz - 1) - 1); // e.g., 1000 -> 999

        // Generate the prefix and create palindromes
        long long prefix = stoll(n.substr(0, (sz + 1) / 2)); // Get the first half
        for (int i = -1; i <= 1; ++i) {
            string newPrefix = to_string(prefix + i);
            string palindrome = newPrefix;
            if (sz % 2 == 0) {
                palindrome += string(newPrefix.rbegin(), newPrefix.rend());
            } else {
                palindrome += string(newPrefix.rbegin() + 1, newPrefix.rend());
            }
            candidates.insert(stoll(palindrome));
        }

        // Remove the original number if it's in the candidates
        candidates.erase(stoll(n));

        // Find the closest palindrome
        long long closest = -1;
        long long minDiff = LLONG_MAX;
        for (const auto& candidate : candidates) {
            long long diff = abs(candidate - stoll(n));
            if (diff < minDiff || (diff == minDiff && candidate < closest)) {
                minDiff = diff;
                closest = candidate;
            }
        }

        return to_string(closest);
    }
};