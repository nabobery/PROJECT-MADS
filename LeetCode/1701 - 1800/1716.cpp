// 1716. Calculate Money in Leetcode Bank

// Solution 1 Naive and Simple Solution
// Time Complexity: O(n/7)
// Space Complexity: O(1)
class Solution {
public:
    int totalMoney(int n) {
        int result = 0;
        for(int i = 0; i < n/7;i++){
            result += i*7 + 28;
        }
        if(n%7) result += (n/7)*(n%7) + (n%7)*(n%7 + 1)/2;
        return result;
    }
};

// Solution 2 Mathematical Solution
// Time Complexity: O(1)
// Space Complexity: O(1)
class Solution {    
public:
    int totalMoney(int n) {
        int result = 0, weeks = n/7, days = n%7;
        result += 28*weeks + 7*(weeks-1)*weeks/2;
        result += (weeks + 1)*days + days*(days-1)/2;
        return result;
    }
};