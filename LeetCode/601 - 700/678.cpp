// 678. Valid Parenthesis String


// Solution 1 by keeping track of the number of open brackets '('
// The number of open brackets should be in the range [mn, mx]
// The string is valid in the end if mn == 0 and mx >= 0
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool checkValidString(string s) {
        int mn = 0, mx = 0;
        for(char c : s){
            // if c is '(' then increment both mn and mx increasing the number of open brackets
            if(c == '('){
                mn++; mx++;
            }
            // if c is ')' then decrement both mn and mx because ')' can be matched with '(' decreasing the number of open brackets
            else if(c == ')'){
                mn--; mx--;
            }
            // if c is '*' then it can be matched with ')' or made into '('
            else{
                mn--; mx++;
            }
            // if at any point the number of open brackets is less than 0 then return false because ')' cannot be matched with '('
            if(mx < 0) return false;
            // if mn is less than 0 then make it 0 because the minimum number of open brackets cannot be negative and continue (this is possible by treating '*' as empty string)
            if(mn < 0) mn = 0;
        }
        return mn == 0;
    }
};

// Cleaner version of the above solution
class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0;
        for(char c : s){
            left += c == '(' ? 1 : -1;
            right += c != ')' ? 1 : -1;
            if(right < 0) break;
            left = max(left, 0);
        }
        return left == 0;
    }
};


// Solution 2 by using Top Down DP
// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return isValid(s, 0, 0, dp);
    }
    bool isValid(const string& s, int index, int openCount, vector<vector<int>>& dp){
        // if index reaches the end of the string then return true if the number of open brackets is 0
        if(index == s.size()) return openCount == 0;
        // if the number of open brackets is less than 0 then return false
        if(openCount < 0) return false;
        // if the value is already calculated then return the value
        if(dp[index][openCount] != -1) return dp[index][openCount];
        // if the character is '(' then increment the number of open brackets and move to the next index
        if(s[index] == '(') return dp[index][openCount] = isValid(s, index + 1, openCount + 1, dp);
        // if the character is ')' then decrement the number of open brackets and move to the next index
        if(s[index] == ')') return dp[index][openCount] = isValid(s, index + 1, openCount - 1, dp);
        // if the character is '*' then it can be matched with ')' or made into '(' or left empty
        return dp[index][openCount] = isValid(s, index + 1, openCount, dp) || isValid(s, index + 1, openCount + 1, dp) || isValid(s, index + 1, openCount - 1, dp);
    }
};

// Solution 3 by using Bottom Up DP
// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
        dp[n][0] = true;
        for(int i = n - 1; i >= 0; i--){
            for(int openCount = 0; openCount <= n; openCount++){
                if(s[i] == '(')
                    dp[i][openCount] = openCount < n && dp[i+1][openCount+1];
                else if(s[i] == ')')
                    dp[i][openCount] = openCount > 0 && dp[i+1][openCount-1];
                else
                    dp[i][openCount] = dp[i+1][openCount] || (openCount < n && dp[i+1][openCount+1]) || (openCount > 0 && dp[i+1][openCount-1]);
            }
        }
        return dp[0][0];
    }
};

// Solution 4 by using 2 Stacks
// Time complexity: O(n)
// Space complexity: O(n)
// The idea is to keep track of the indices of open brackets and stars
// If a closing bracket is found then it can be matched with an open bracket or a star
// If a star is found then it can be matched with an open bracket or left empty
// If at the end there are open brackets left then they can be matched with stars
// If at any point there are no open brackets or stars left or the open bracket index is greater than the star index then return false
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open, star;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') open.push(i);
            else if(s[i] == '*') star.push(i);
            else{
                if(!open.empty()) open.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }
        while(!open.empty() && !star.empty()){
            if(open.top() > star.top()) return false;
            open.pop();
            star.pop();
        }
        return open.empty();
    }
};


// Solution 5 by using 2 pointers by keeping track of the number of open brackets '(' and closing brackets ')'
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool checkValidString(string s) {
        int open = 0, close = 0, n = s.size();
        for(int i = 0; i < n; i++){
            open += (s[i] != ')') ? 1 : -1;
            close += (s[n-i-1] != '(') ? 1 : -1;
            if(open < 0 || close < 0) return false;
        }
        return true;
    }
};


