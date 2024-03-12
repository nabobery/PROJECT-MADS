// 2864. Maximum Odd Binary Number

// Solution 1 Simple greedy solution by keeping all 1s to the left and 0s to the right and 1 at the end 
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size(), cnt = 0;
        string res(n, '0');
        for(char ch : s) if(ch == '1') cnt++;
        res[n-1] = '1';
        for(int i = 0; i < cnt-1;i++) res[i] = '1';
        return res;
    }
};

// Cleaner Solution 1 without using resultant string
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size(), cnt = 0;
        for(char ch : s) if(ch == '1') cnt++;
        s[n-1] = '1';
        for(int i = 0; i < n-1;i++){
            if(i < cnt-1) s[i] = '1';
            else s[i] = '0';
        }
        return s;
    }
};