// 3714. Longest Balanced Substring II

// Solution 1: Prefix Sum + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size(), res = 1;
        // case 1
        for(int i = 0; i < 3;i++){
            int count = 0;
            for(int j = 0; j < n;j++){
                if(s[j]-'a' == i){
                    count++;
                    res = max(res, count);
                }
                else count = 0;
            }
        }
        // case 2
        for(int i = 0;i < 3;i++){
            int char1 = i, char2 = (i+1)%3;
            int c1 = 0, c2 = 0;
            unordered_map<int,int> diffToIndex;
            diffToIndex[0] = -1;
            for(int j = 0; j < n;j++){
                if(s[j]-'a' == char1) c1++;
                else if(s[j]-'a' == char2) c2++;
                else{
                    diffToIndex.clear();
                    diffToIndex[0] = j;
                    c1 = c2 = 0;
                }
                if(!diffToIndex.count(c1-c2)) diffToIndex[c1-c2] = j;
                else res = max(res, j-diffToIndex[c1-c2]);
            }
        }
        // case 3
        map<pair<int,int>, int> diffPairsToIndex;
        diffPairsToIndex[{0, 0}] = -1;
        vector<int> cnt(3, 0);
        for(int j = 0; j < n;j++){
            cnt[s[j]-'a']++;
            int c1 = cnt[0], c2 = cnt[1], c3 = cnt[2];
            if(!diffPairsToIndex.count({c2-c1, c3-c1})) diffPairsToIndex[{c2-c1, c3-c1}] = j;
            else res = max(res, j-diffPairsToIndex[{c2-c1, c3-c1}]);
        }
        return res;
    }
};

// Elegant Solution: Prefix Sum + Hash Map + Bit Mask
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size(), ans = 0;

        // Case 1: Maximum contiguous block of a single character
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && s[j] == s[i])
                j++;
            ans = max(ans, j - i);
        }

        // Helper for Cases 2 and 3
        auto solve = [&](const vector<int>& subset) {
            unordered_map<long long, int> seen;
            seen[0] = -1;
            int cnt[3] = {0, 0, 0}, mask = 0;
            for (int c : subset)
                mask |= (1 << c);

            for (int i = 0; i < n; ++i) {
                int cur = s[i] - 'a';
                if (!(mask & (1 << cur))) {
                    seen.clear();
                    seen[0] = i;
                    cnt[0] = cnt[1] = cnt[2] = 0;
                    continue;
                }

                cnt[cur]++;
                long long key = (subset.size() == 2)
                                    ? (cnt[subset[0]] - cnt[subset[1]])
                                    : ((long long)(cnt[0] - cnt[1]) << 32 |
                                       (unsigned int)(cnt[0] - cnt[2]));

                if (seen.find(key) != seen.end())
                    ans = max(ans, i - seen[key]);
                else
                    seen[key] = i;
            }
        };

        // Case 2
        solve({0, 1});
        solve({1, 2});
        solve({0, 2}); 
        // Case 3   
        solve({0, 1, 2}); 

        return ans;
    }
};