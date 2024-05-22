// 131. Palindrome Partitioning

// Solution 1 Naive and not properly optimised using Recursion
// Time Complexity O(n*2^n)
// Space Complexity: O(n)
class Solution {
public:
    vector<vector<string>> res;
    set<vector<int>> visited;
    bool isPalindrome(string& str){
        int n = str.size();
        for(int i = 0; i < n/2;i++)
            if(str[i] != str[n-1-i]) return false;
        return true;
    }
    void helper(string& s, int i, vector<int>& curr){
        int n = s.size();
        if(i >= n){
            int b = curr.back();
            string t = s.substr(b+1);
            if(isPalindrome(t)){
                vector<string> temp;
                if(b != n-1) curr.push_back(n-1);
                if(!visited.count(curr)){
                    for(int j = 1; j < curr.size(); j++)
                        temp.push_back(s.substr(curr[j-1]+1, curr[j] - curr[j-1]));
                    res.push_back(temp);
                    visited.insert(curr);
                }
                if(b != n-1) curr.pop_back();
            }
            return;
        }
        string t = s.substr(curr.back()+1, i-curr.back());
        if(isPalindrome(t)){
            curr.push_back(i);
            helper(s, i+1, curr);
            curr.pop_back();
        }
        helper(s, i+1, curr);
    }
    vector<vector<string>> partition(string s) {
        vector<int> curr = {-1};
        helper(s,0, curr);
        return res;
    }
};

// Solution 2 optimised using recursion and backtracking 
// Time Complexity O(n*2^n)
// Space Complexity: O(n)
class Solution {
public:
    bool isPalindrome(string &s, int low, int high){
        while(low < high)
            if(s[low++] != s[high--]) return false;
        return true;
    }

    void helper(vector<vector<string>> &result, string &s, int start,vector<string> &curr){
        if(start >= s.length()) result.push_back(curr);
        for(int end = start; end < s.length();end++){
            if(isPalindrome(s,start,end)){
                curr.push_back(s.substr(start,end-start+1));
                helper(result,s,end+1,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        helper(result, s,0,curr);
        return result;
    }
};

// Solution 3 optimised using recursion, backtracking and Memoization
// Time Complexity O(n*2^n)
// Space Complexity: O(n)
class Solution {
public:
    void helper(vector<vector<string>> &result, string &s, int start, vector<string> &curr, vector<vector<bool>> &dp) {
        if (start >= s.length()) result.push_back(curr);
        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                curr.push_back(s.substr(start, end - start + 1));
                helper(result, s, end + 1, curr, dp);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp (n, vector <bool> (n, false));
        vector<vector<string>> result;
        vector<string> curr;
        helper(result, s, 0, curr, dp);
        return result;
    }
}; 

