// 165. Compare Version Numbers

// Solution 1 using Two Pointers
// Time complexity: O(min(n1, n2))
// Space complexity: O(1)
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

// Solution 2 using stringstream
// Time complexity: O(n1 + n2)
// Space complexity: O(n1 + n2)

class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1), ss2(version2);
        string rev1, rev2;
        while(!ss1.eof() || !ss2.eof()){
            int num1 = 0, num2 = 0;
            if(getline(ss1, rev1, '.')) num1 = stoi(rev1);
            if(getline(ss2, rev2, '.')) num2 = stoi(rev2);
            if(num1 > num2) return 1;
            else if(num1 < num2) return -1;
            rev1 = rev2 = "";
        }
        return 0;
    }
};
