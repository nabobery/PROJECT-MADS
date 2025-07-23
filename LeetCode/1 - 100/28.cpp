// 28. Find the Index of the First Occurrence in a String

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size(), h = haystack.size(), p1 = 0, start = -1;
        if(n > h) return -1;
        bool flag = true;
        for(int i = 0; i < h;i++){
            if(p1 == 0 && needle[p1] == haystack[i]){
                start = i;
                p1++;
            }
            else if(p1 != 0 && (needle[p1] == haystack[i] && needle[p1-1] == haystack[i-1])) p1++;
            else if(p1 != 0 && needle[p1] != haystack[i]){
                p1 = 0;
                i = start;
            }
            if(p1 == n) break;
        }
        if(p1 != n || start == -1) return -1;
        return start;
    }
};