// 2124. Check if All A's Appears Before All B's

// Solution 1 Simple Linear Scan
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    bool checkString(string s) {
        int last_a = -1, first_b = 101, n = s.size();
        for(int i = 0; i < n;i++){
            if(s[i] == 'a') last_a = i;
            else if(first_b == 101) first_b = i; 
        }
        return last_a < first_b;
    }
};