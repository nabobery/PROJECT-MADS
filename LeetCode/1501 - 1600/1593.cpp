// 1593. Split a String Into the Max Number of Unique Substrings

// Solution 1 using Recursion + Backtracking
// Time complexity: O(n!)
// Space complexity: O(n)
class Solution {
public:
    int res;
    void helper(string& s, int ind, unordered_set<string>& st, string curr){
        if(ind >= s.size()){
            res = max(res, int(st.size()));
            return;
        }
        curr += s[ind];
        helper(s, ind+1, st, curr);
        if(!st.count(curr)){
            st.insert(curr);
            helper(s, ind+1, st, "");
            st.erase(curr);
        }
    }
    int maxUniqueSplit(string s) {
        res = 0;
        unordered_set<string> st;
        helper(s, 0, st, "");
        return res;
    }
};


// Solution 2 using Recursion + Backtracking
// Time complexity: O(n!)
// Space complexity: O(n)
class Solution {
public:
    int res;
    void helper(string& s, int ind, unordered_set<string>& st){
        if(ind >= s.size()){
            res = max(res, int(st.size()));
            return;
        }
        string curr = "";
        for(int i = ind; i < s.size(); i++){
            curr += s[i];
            if(!st.count(curr)){
                st.insert(curr);
                helper(s, i+1, st);
                st.erase(curr);
            }
        }
    }
    int maxUniqueSplit(string s) {
        res = 0;
        unordered_set<string> st;
        helper(s, 0, st);
        return res;
    }
};
