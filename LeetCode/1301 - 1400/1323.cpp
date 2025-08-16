// 1323. Maximum 69 Number

// Solution 1: Greedy Approach by replacing the first '6' with '9'
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maximum69Number (int num) {
        string num_str = to_string(num);
        for(char& ch : num_str){
            if(ch == '6'){
                ch = '9';
                break;
            }
        }
        return stoi(num_str);
    }
};