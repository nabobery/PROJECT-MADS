// 241. Different Ways to Add Parentheses

// Solution 1 using Recursion and Memoization
// Time complexity: O(2^n)
// Space complexity: O(2^n)
class Solution {
public:
    // dp to store the results of the subproblems
    unordered_map<string, vector<int>> dp;
    // helper function to calculate the results of the subproblems
    vector<int> helper(string expr){
        // if the result of the subproblem is already calculated, return it
        if(dp.count(expr)) return dp[expr];
        // vector to store the results of the subproblems
        vector<int> results;
        // iterate through the expression
        for (int i = 0; i < expr.size(); ++i) {
            char ch = expr[i];
            // if the character is an operator
            if (ch == '+' || ch == '-' || ch == '*') {
                // split the expression into left and right parts
                string left = expr.substr(0, i), right = expr.substr(i + 1);
                // calculate the results of the left and right parts
                vector<int> leftResults = helper(left), rightResults = helper(right);
                // calculate the result of the subproblem by combining the results of the left and right parts left op right
                for (int leftValue : leftResults) {
                    for (int rightValue : rightResults) {
                        int result = 0;
                        if (ch == '+') 
                            result = leftValue + rightValue;
                        else if (ch == '-') 
                            result = leftValue - rightValue;
                        else if (ch == '*') 
                            result = leftValue * rightValue;
                        results.push_back(result);
                    }
                }
            }
        }
        // if the expression is a number, add it to the results
        if (results.empty()) results.push_back(stoi(expr));
        // store the results of the subproblem in the dp
        return dp[expr] = results;
    }
    vector<int> diffWaysToCompute(string expression) {
        return helper(expression);
    }
};


// Solution 2 using Iterative Approach
// Time complexity: O(2^n)
// Space complexity: O(2^n)
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;
        // iterate through the expression
        for (int i = 0; i < expression.size(); ++i) {
            char ch = expression[i];
            // if the character is an operator
            if (ch == '+' || ch == '-' || ch == '*') {
                // split the expression into left and right parts
                string left = expression.substr(0, i), right = expression.substr(i + 1);
                // calculate the results of the left and right parts
                vector<int> leftResults = diffWaysToCompute(left), rightResults = diffWaysToCompute(right);
                // calculate the result of the subproblem by combining the results of the left and right parts left op right
                for (int leftValue : leftResults) {
                    for (int rightValue : rightResults) {
                        int result = 0;
                        if (ch == '+') 
                            result = leftValue + rightValue;
                        else if (ch == '-') 
                            result = leftValue - rightValue;
                        else if (ch == '*') 
                            result = leftValue * rightValue;
                        results.push_back(result);
                    }
                }
            }
        }
        // if the expression is a number, add it to the results
        if (results.empty()) results.push_back(stoi(expression));
        return results;
    }
};