// 1945. Sum of Digits of String After Convert

// Solution 1: Straightforward Approach
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int getLucky(string s, int k) {
        string tr = "";
        for(char ch : s) tr += to_string((ch - 'a') + 1);
        while(k--){
            int sum = 0;
            for(char ch : tr) sum += (ch - '0');
            tr = to_string(sum);
        }
        return stoi(tr);
    }
};