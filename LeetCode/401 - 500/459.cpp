// 459. Repeated Substring Pattern

// Solution 1: Using Divisors
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = 1; i <= n/2;i++){
            if(n% i == 0){
                string t = "";
                for(int j = 0; j < n/i;j++){
                    t += s.substr(0,i);
                } 
                if(t == s) return true;
            }
        }
        return false;
    }
};

// Solution 2: Optimized Solution 1
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        bool flag = false;
        for(int i = 2; i <= n;i++){
            if(n/i == 0) break;
            if(n% i == 0){
                string temp = s.substr(0,n/i), t = "";
                for(int j = 0; j < n;j += n/i){
                    t += temp;
                } 
                if(t == s){
                    flag = true;
                    break;
                }
            }
        }
        return flag;
    }
};

// Solution 3: Using String Concatenation
// Time Complexity O(n) 

// Basic Idea: If we have a string S which is a repeating pattern of some substring s, then we can create a new string T which is S+S.  
// Now, if we remove the first and the last character from T, we get a new string R = T.substr(1, T.size()-2).
// If the string R has S as a substring, then we can say that S has a repeating pattern. To see why this is true, consider the following example:
// S = "abab"
// T = "abababab"
// T.substr(1, T.size()-2) = "bababa"
// Now, we can clearly see that S exists as a substring of T.substr(1, T.size()-2).
// If S has a repeating pattern, then T will satisfy the above condition.
// Using this idea, we can create a new string T = S+S, and check if S exists in T.substr(1, T.size()-2).
// If it does, then S has a repeating pattern.
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s+s;
        return (t.substr(1,t.size() - 2).find(s) != -1);
    }
};