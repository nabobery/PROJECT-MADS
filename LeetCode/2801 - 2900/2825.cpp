// 2825. Make String a Subsequence Using Cyclic Increments

// Solution 1 using 2 Pointers
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int p1 = 0, p2 = 0;
        int n1 = str1.size(), n2 = str2.size();
        if (n2 > n1) return false;
        while (p1 < n1 && p2 < n2) {
            if (str1[p1] == str2[p2] || (str1[p1] - 'a' + 1) % 26 + 'a' == str2[p2]) {
                p2++;
            }
            p1++;
        }
        return p2 == n2;
    }
};