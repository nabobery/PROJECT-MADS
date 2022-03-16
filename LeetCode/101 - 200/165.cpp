// 165. Compare Version Numbers
// my naive O(max(m,n)) time solution
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int rev1, rev2;
        int p1 = 0, p2 = 0;
        int n1 = version1.size(), n2 = version2.size();
        while(p1 < n1 || p2 < n2){
            rev1 = 0, rev2 = 0;
            while(p1 < n1 && version1[p1] != '.'){
                rev1 = 10*rev1 + (version1[p1] - '0');
                p1++;
            }
            while(p2 < n2 && version2[p2] != '.'){
                rev2 = 10*rev2 + (version2[p2] - '0');
                p2++;
            }
            if(rev1 == rev2){
                p1++;
                p2++;
                continue;
            }
            else if(rev1 > rev2) return 1;
            else return -1;
        }
        return 0;
    }
};

