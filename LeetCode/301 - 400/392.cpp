// 392. Is Subsequence
// my naive solution using two pointers
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n1 > n2) return false;
        if(s == t) return true;
        int p1 = 0, p2 = 0;
        while(p2 < n2 && p1 < n1){
            char temp = s[p1];
            while(p2 < n2 && t[p2] != temp){
                p2++;
            }
            if(p1 >= n1 || p2 >= n2) break;
            p1++;
            p2++;
        }
        return(p1 == n1);
    }
};


