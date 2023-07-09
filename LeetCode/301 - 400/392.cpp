// 392. Is Subsequence

// O(n) time and O(1) space solution using two pointers
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n1 > n2) return false;
        if(s == t) return true;
        int p1 = 0, p2 = 0;
        // p1 is the pointer for s and p2 is the pointer for t
        // p1 is incremented only when a match is found
        // p2 is incremented every time
        while(p2 < n2 && p1 < n1){
            char temp = s[p1];
            while(p2 < n2 && t[p2] != temp){
                p2++;
            }
            if(p1 >= n1 || p2 >= n2) break;
            p1++;
            p2++;
        }
        // if p1 is equal to n1, then the entire string s was found in t
        return(p1 == n1);
    }
};


