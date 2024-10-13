// 386. Lexicographical Numbers 

// Solution 1: Recursive
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> res;
    void helper(int num, int n){
        if(num > n) return;
        res.push_back(num);
        num *= 10;
        for(int i = 0; i <= 9;i++)
            helper(i+num, n);
    }
    vector<int> lexicalOrder(int n) {
        for(int i = 1; i <= 9;i++)
            helper(i, n);
        return res;
    }
};

// Solution 2: Iterative
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int cur = 1;
        for(int i = 1; i <= n; i++){
            res.push_back(cur);
            if(cur*10 <= n)
                cur *= 10;
            else{
                if(cur >= n) cur /= 10;
                cur += 1;
                while(cur % 10 == 0) cur /= 10;
            }
        }
        return res;
    }
};