// 2843. Count Symmetric Integers

// Solution 1: Simple and Straightforward solution
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int res = 0;
            int start = low;
            while (int(log10(start)) % 2 != 1) start++;
            for (int i = start; i <= high; i++) {
                string num = to_string(i);
                int digs = num.size();
                if (digs % 2 != 0) continue; 
                int s1 = 0, s2 = 0;
                for (int j = 0; j < digs / 2; j++) {
                    s1 += num[j] - '0';
                    s2 += num[digs / 2 + j] - '0';
                }
                if (s1 == s2) res++;
            }
            return res;
        }
};