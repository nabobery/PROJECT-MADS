// 2381. Shifting Letters II

// Solution 1: Using Prefix Sum using vector and storing the ranges indices 
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    int mp[50001];
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        string res;
        memset(mp, 0, sizeof(mp));
        int n = s.size();
        for(auto& shift: shifts){
            int l = shift[0], r = shift[1], direction = shift[2];
            if(direction == 1){
                mp[l]++;
                if(r+1 < n) mp[r+1]--;
            }
            else{
                mp[l]--;
                if(r+1 < n) mp[r+1]++;
            }
        }
        int curr = 0;
        for(int i = 0; i < n;i++){
            curr = ((curr + mp[i])% 26 + 26) % 26;
            res += ((s[i] - 'a' + curr) % 26) + 'a';
        }
        return res;
    }
};