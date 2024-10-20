// 1545. Find Kth Bit in Nth Binary String

// Solution 1 using Recursion
// Time complexity: O(2^n)
// Space complexity: O(2^n)
class Solution {
public:
    string helper(int n){
        if(n == 0) return "0";
        string sprev = helper(n-1), sinv = sprev;
        for (char& c : sinv) 
            c = (c == '0') ? '1' : '0';
        reverse(sinv.begin(), sinv.end());
        return sprev + "1" + sinv;
    }

    char findKthBit(int n, int k) {
        string sn = helper(n);
        return sn[k-1];
    }
};

// Efficient solution using Recursion
class Solution {
public:
    char findKthBit(int n, int k) {
        int length = (1 << n) - 1; 
        return helper(n, k, length);
    }
    
private:
    char helper(int n, int k, int length) {
        if (n == 1) return '0';  // Base case

        int mid = (length + 1) / 2;  // Middle index of the string

        if (k == mid) return '1';  // If k is the middle, return '1'
        else if (k < mid) {
            return helper(n - 1, k, (length - 1) / 2);  // Left half
        } else {
            // Right half
            int newK = length - k + 1;
            char result = helper(n - 1, newK, (length - 1) / 2);
            return (result == '0') ? '1' : '0';  // Invert the result
        }
    }
};