// 1704. Determine if String Halves Are Alike

// Simple and Straightforward Solution
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    bool halvesAreAlike(string s) {
        int n =s.size(),cnt = 0;
        for(int i = 0; i < n/2;i++){
            if(isVowel(s[i])) cnt++;
            if(isVowel(s[i+n/2])) cnt--;
        }
        return cnt==0;
    }
};