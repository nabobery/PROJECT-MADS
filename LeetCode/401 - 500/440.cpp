// 440. K-th Smallest in Lexicographical Order

// Solution 1 by using DFS and backtracking (TLE)
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int cnt, res;
    void helper(int num, int& n, int& k){
        if(num > n || cnt == k) return;
        cnt++;
        if(cnt == k) res = num;
        num *= 10;
        for(int i = 0; i <= 9;i++)
            helper(i+num, n, k);
    }
    int findKthNumber(int n, int k) {
        cnt = 0;
        for(int i = 1; i <= 9;i++)
            helper(i, n, k);
        return res;
    }
};

// Solution 2 by keeping track of the number of nodes in the subtree of the current node and moving to the next node accordingly
// Time complexity: O((logn)^2)
// Space complexity: O(1)
class Solution {
public:
    // helper function to count the number of nodes in the subtree of the current node
    int helper(int prefix, int n){
        long res = 0, curr = prefix, next = prefix+1;
        while(curr <= n){
            res += min(long(n+1), next) - curr;
            next *= 10;
            curr *= 10;
        }
        return res;
    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        // move to the next node until k becomes 0
        while(k > 0){
            int count = helper(curr, n);
            // if the number of nodes in the subtree of the current node is less than or equal to k, move to the next node
            if(count <= k){
                k -= count;
                curr++;
            }
            // if the number of nodes in the subtree of the current node is greater than k, move to the next child node
            else{
                curr *= 10;
                k--;
            }
        }
        // return the current node
        return curr;
    }
};


