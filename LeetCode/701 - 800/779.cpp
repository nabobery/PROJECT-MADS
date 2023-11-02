// 779. K-th Symbol in Grammar

// Solution 1: Recursion
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    // n=1 0
    // n=2 01
    // n=3 0110 
    //n=4 01101001
    //n=5 01101001 10010110
    //n=6 0110100110010110 1001011001101001
    // For n > 2 the first half of the string is the same as the string for n-1, the second half is the complement of the string for n-1.
    int helper(int n, int k, bool flag){
        if(n == 1) return flag;
        int temp = pow(2, n-2);
        if(k > temp){
            k -= temp;
            flag = !flag;
        }
        return helper(n-1,k,flag);
    }
    int kthGrammar(int n, int k) {
        return helper(n, k, false);
    }
};

// Solution 2: Iteration
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int kthGrammar(int n, int k) {
        bool flag = false;
        while(n != 1){
            int temp = pow(2, n-2);
            if(k > temp){
                k -= temp;
                flag = !flag;
            }
            n--;
        }
        return flag;
    }
};