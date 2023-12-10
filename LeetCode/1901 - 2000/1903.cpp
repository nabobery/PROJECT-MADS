// 1903. Largest Odd Number in String

// Solution 1: Simple and Easy
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    string largestOddNumber(string num) {
        int t = -1;
        for(int i = 0; i < num.size();i++){
            if((num[i] - '0') % 2) t = i;
        }
        if(t == -1) return "";
        return num.substr(0,t+1);
    }
};

// Backward Traversal Solution 1
class Solution {
public:
    string largestOddNumber(string num) {
        int t = -1;
        for(int i = num.size()-1; i >= 0;i--){
            if((num[i] - '0') % 2){
                t = i;
                break;
            }
        }
        if(t == -1) return "";
        return num.substr(0,t+1);
    }
};