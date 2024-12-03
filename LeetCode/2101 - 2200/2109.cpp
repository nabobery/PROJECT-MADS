// 2109. Adding Spaces to a String

// Solution 1: Using unordered_set
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        unordered_set<int> sp(spaces.begin(), spaces.end());
        for(int i = 0; i < s.size();i++){
            if(sp.count(i)) res += " ";
            res += s[i];
        }
        return res;
    }
};

// Solution 2: Efficient solution using pointer
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        int p = 0;
        for(int i = 0; i < s.size();i++){
            if(p < spaces.size() && spaces[p] == i){
                res += " ";
                p++;
            }
            res += s[i];
        }
        return res;
    }
};