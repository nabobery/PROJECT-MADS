// 680. Valid Palindrome II
// greedy O(n) time solution
class Solution {
public:
    // check i given substring is paindrome
    bool checkPalindrome(string s){
        for(int i = 0; i < s.size()/2;i++){
            if(s[i] != s[s.size() - i -1]) return false;
        }
        return true;
    }

    bool validPalindrome(string s) {
        // two pointers
        int i = 0, j = s.size() - 1;
        while(i < j){
            // if a char isn't equal with the char at the other end check if removing any of them can make the string a palindrome
            if(s[i] != s[j]){
                return (checkPalindrome(s.substr(i+1,j-i)) || checkPalindrome(s.substr(i,j-i)));
            }
            i++;
            j--;
        }
        // if all chars are equal then it's a palindrome
        return true;
    }
};
