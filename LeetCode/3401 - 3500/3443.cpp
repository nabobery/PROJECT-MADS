// 3443. Maximum Manhattan Distance After K Changes


// Solution 1: Greedy Approach (Failed)
class Solution {
public:
    unordered_map<char, int> dirIndex = {
        {'N', 0},
        {'S', 1},
        {'E', 2},
        {'W', 3}
    };
    int cnt[4], change[4];
    int maxDistance(string s, int k) {
        memset(cnt, 0, sizeof(cnt));
        for(char& ch : s) cnt[dirIndex[ch]]++;
        int res = 0;
        int ns = min(cnt[0], cnt[1]), ind = (ns == cnt[0]) ? 0 : 1;
        if(k > 0){
            change[ind] = min(ns, k);
            k -= min(ns, k);
        }
        int ew = min(cnt[2], cnt[3]);
        ind = (ew == cnt[2]) ? 2 : 3;
        if(k > 0){
            change[ind] = min(ew, k);
            k -= min(ew, k);
        }
        memset(cnt, 0, sizeof(cnt));
        for(char& ch : s){
            ind = dirIndex[ch];
            if(change[ind] > 0){
                if(ind %2) cnt[ind-1]++;
                else cnt[ind+1]++;
                change[ind]--;
            }
            else cnt[ind]++;
            res = max(abs(cnt[0] - cnt[1]) + abs(cnt[2] - cnt[3]), res);
        }
        return res;
    }
};

// Solution 2: Brute Force 
// Time Complexity: O(n * 4)
// Space Complexity: O(1)
class Solution {
public:
    unordered_map<char, int> dirIndex = {
        {'N', 0},
        {'S', 1},
        {'E', 2},
        {'W', 3}
    };
    int cnt[4];
    string possibleDirections[4] = {"NE", "NW", "SE", "SW"};
    int maxDistance(string s, int k) {
        memset(cnt, 0, sizeof(cnt));
        for(char& ch : s) cnt[dirIndex[ch]]++;
        int res = 0;
        for(int i = 0; i < 4;i++){
            int tk = k;
            memset(cnt, 0, sizeof(cnt));
            for(char& ch : s){
                if(tk > 0 && possibleDirections[i][0] != ch && possibleDirections[i][1] != ch){
                    cnt[dirIndex[possibleDirections[i][0]]]++;
                    tk--;
                }
                else cnt[dirIndex[ch]]++;
                res = max(res, abs(cnt[0] - cnt[1]) + abs(cnt[2] - cnt[3]));
            }
        }
        return res;
    }
};

// Solution 3: (Inspired from Solution 1) (check for every character at every step)
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maxDistance(string s, int k) {
        int res = 0, no = 0, so = 0, ea = 0, we = 0;
        for(char& ch : s){
            if(ch == 'N') no++;
            else if(ch == 'S') so++;
            else if (ch == 'E') ea++;
            else we++;
            int t1 = min({no, so, k}), t2 = min({ea, we, k - t1});
            res = max(res, abs(no-so) + t1* 2 + abs(ea-we) + t2*2);
        }
        return res;
    }
};
