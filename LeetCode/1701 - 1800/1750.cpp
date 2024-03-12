// 1750. Minimum Length of String After Deleting Similar Ends

// Solution 1 using Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int minimumLength(string s) {
        int n = s.size(), l = 0, r = n-1;
        while(l < r){
            if(s[l] != s[r]) break;
            char temp = s[l];
            while(l < r && temp == s[l]) l++;
            if(l == r) return 0;
            while(l < r && temp == s[r]) r--;
        }
        return (l > r ? 0 : r-l+1);
    }
};

// Concise and Clean Solution 1
class Solution {
public:
    int minimumLength(string s) {
        int n = s.size(), l = 0, r = n-1;
        while(l < r){
            if(s[l] != s[r]) return r-l+1;
            while(l < r && s[l] == s[l+1]) l++;
            while(l < r && s[r] == s[r-1]) r--;
            l++, r--;
        }
        return (l > r ? 0 : r-l+1);
    }
};