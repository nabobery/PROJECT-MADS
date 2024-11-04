// 1957. Delete Characters to Make Fancy String

// Solution 1 Simple Iteration
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string makeFancyString(string s) {
        int curr = 1;
        string res;
        res += s[0];
        for(int i = 1; i < s.size();i++){
            if(s[i] == s[i-1]){
                curr++;
                if(curr >= 3) continue;
            }
            else curr = 1;
            res += s[i];
        }
        return res;
    }
};