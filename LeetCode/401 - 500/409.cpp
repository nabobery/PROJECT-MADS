// 409. Longest Palindrome
// my naive solution
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map <char,int> freq;
        for(char ch : s){
            freq[ch]++;
        }
        int result = 0;
        bool flag = false;
        for(auto itr : freq){
            if(itr.second % 2 == 0){
                result += itr.second;
            }
            else{
                result += (itr.second) - 1;
                flag = true;
            }
        }
        if(flag) result += 1;
        return result;
    }
};

// more efficient way using array
class Solution {
public:
    int longestPalindrome(string s) {
        int count[128] = {0};
        for(char c : s) count[c]++;
        int result = 0;
        for(int c : count){
            result += (c/2)*2;
        }
        if(result < s.length()) result++;
        return result;
    }
};

