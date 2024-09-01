// 3016. Minimum Number of Pushes to Type Word II

// Solution 1: Greedy
// Time complexity: O(n + 26log26) = O(n)
// Space complexity: O(1)
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26, 0);
        for(char ch : word) cnt[ch-'a']++;
        sort(cnt.begin(), cnt.end());
        int res = 0, push = 1, prev = 25;
        for(int i = 25; i >= 0; i--){
            if(cnt[i] == 0) break;
            if(prev - i > 7){
                prev = i;
                push++;
            }
            res += push*cnt[i];
        }
        return res;
    }
};

