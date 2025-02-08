// 1790. Check if One String Swap Can Make Strings Equal

// Solution 1: by checking the number of unmatched characters and their frequency
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for(char&ch : s1) cnt1[ch-'a']++;
        for(char&ch : s2) cnt2[ch - 'a']++;
        if(cnt1 != cnt2) return false;
        int nomatches = 0, n = s1.size();
        for(int i = 0; i < n;i++){
            if(s1[i] != s2[i]) nomatches++;
        }
        return (nomatches <= 2);
    }
};