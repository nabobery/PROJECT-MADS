// 131. Palindrome Partitioning
// using dfs and backtracking time : O(n*2^n) n is size of string ; space = O(n)(call stack)
class Solution {
public:
    bool isPalindrome(string &s, int low, int high){
        while(low < high){
            if(s[low++] != s[high--]) return false;
        }
        return true;
    }

    void dfs(vector<vector<string>> &result, string &s, int start,vector<string> &currList){
        if(start >= s.length()) result.push_back(currList);
        for(int end = start; end < s.length();end++){
            if(isPalindrome(s,start,end)){
                currList.push_back(s.substr(start,end-start+1));
                dfs(result,s,end+1,currList);
                currList.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currList;
        dfs(result, s,0,currList);
        return result;
    }
};

// using dynamic programming and dfs(is faster than 1st approach) time : O(n*2^n) n is size of string ; space = O(n^2)(matrix)
class Solution {
public:
    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currList, vector<vector<bool>> &dp) {
        if (start >= s.length()) result.push_back(currList);
        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                currList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currList, dp);
                currList.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool>> dp (len, vector <bool> (len, false));
        vector<vector<string>> result;
        vector<string> currList;
        dfs(result, s, 0, currList, dp);
        return result;
    }
};

