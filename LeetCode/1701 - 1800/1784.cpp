// 1784. Check if Binary String Has at Most One Segment of Ones

// Solution 1: Using a flag to track segments of ones (state machine approach)
// Time Complexity: O(n), where n is the length of the input string
// Space Complexity: O(1)
class Solution {
public:
    bool checkOnesSegment(string s) {
        // string should be of form 1+0*
        int state = 0;
        for(char& ch : s){
            if(ch == '1'){
                if(state == 0) continue;
                else{
                    state = -1;
                    break;
                }
            }
            else{
                if(state == 0) state = 1;
                else if(state == 1) continue;
                else{
                    state = -1;
                    break;
                }
            }
        }
        return state != -1;
    }
};

// Solution 2: Using string find to check for the presence of "01"
// Time Complexity: O(n), where n is the length of the input string
// Space Complexity: O(1)
class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};

// Solution 3: Using string find to check for the presence of "01" using a loop
// Time Complexity: O(n), where n is the length of the input string
// Space Complexity: O(1)
class Solution {
public:
    bool checkOnesSegment(string s) {
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '1' && s[i - 1] == '0') {
                return false;
            }
        }
        return true;
    }
};