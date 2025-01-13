// 848. Shifting Letters

// Solution 1 using Prefix Sum
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        string res;
        int n = s.size(), curr = 0, sum = 0;
        for(int shift : shifts){
            sum += shift % 26;
            sum %= 26;
        }
        for(int i = 0; i < n;i++){
            int shift = (sum - curr + 26) % 26;
            int newPos = ((s[i] - 'a') + shift) % 26;
            res += ('a' + newPos);
            curr += shifts[i] % 26;
            curr %= 26;
        }
        return res;
    }
};