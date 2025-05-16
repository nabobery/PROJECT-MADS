// 3335. Total Characters in String After Transformations I

// Solution 1: Straightforward simulation
// Time Complexity: O(n + t)
// Space Complexity: O(1)
class Solution {
public:
    const int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        long res = 0;
        vector<long> cnt(26 , 0), temp(26);
        for(auto &ch : s) cnt[ch -'a']++;
        for(int i =0 ; i < t;i++){
            for(int j = 0; j < 25;j++) temp[j+1] = cnt[j];
            temp[0] = cnt[25];
            temp[1] = (temp[1] + cnt[25]) % mod;
            cnt = temp;
        }
        for(auto& c : cnt) res = (res + c) % mod;
        return res % mod;
    }
};