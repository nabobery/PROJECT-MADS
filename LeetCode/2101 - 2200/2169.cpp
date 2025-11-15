// 2169. Count Operations to Obtain Zero

// Solution 1 using Recursion
// Time Complexity: O(max(num1, num2))
// Space Complexity: O(max(num1, num2))
class Solution {
public:
    int countOperations(int num1, int num2) {
        if(!num1 || !num2) return 0;
        if(num1 == num2) return 1;
        else if(num1 < num2) return 1 + countOperations(num1, num2-num1);
        return 1 + countOperations(num1 -num2, num2);
    }
};

// Solution 2 using Iteration
// Time Complexity: O(log(min(num1, num2)))
// Space Complexity: O(1)
class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;
        while(num1 && num2) {
            if(num1 >= num2) {
                count += num1 / num2;
                num1 = num1 % num2;
            } else {
                count += num2 / num1;
                num2 = num2 % num1;
            }
        }
        return count;
    }
};