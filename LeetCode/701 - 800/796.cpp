// 796. Rotate String

// Solution 1 by string matching with all the rotations
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    string rotate(string s, int x){
        string res;
        int n = s.size();
        for(int i = 0; i < n;i++)
            res += s[(i+x) % n];
        return res;
    }
    bool rotateString(string s, string goal) {
        if(s == goal) return true;
        for(int i = 1; i < s.size();i++){
            string temp = rotate(s, i);
            if(goal == temp) return true;
        }
        return false;
    }
};

