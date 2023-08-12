// 125. Valid Palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size(), l = 0, r = n-1;
        char low, high;
        while(l < r){
            while(l < r){
                if((s[l] >= 65 && s[l] <= 90) || (s[l] >= 97 && s[l] <= 122) || (s[l] >= 48 && s[l] <= 57)){
                    if(s[l] >= 65 && s[l] <= 90) low = s[l] - 65 + 'a';
                    else low = s[l];
                    break;
                }
                l++;
            }
            high = low;
            while(l < r){
                if((s[r] >= 65 && s[r] <= 90) || (s[r] >= 97 && s[r] <= 122) || (s[r] >= 48 && s[r] <= 57)){
                    if(s[r] >= 65 && s[r] <= 90) high = s[r] - 65 + 'a';
                    else high = s[r];
                    break;
                }
                r--;
            }
            if(low != high) return false;
            l++;
            r--;
        }
        return true;
    }
};;