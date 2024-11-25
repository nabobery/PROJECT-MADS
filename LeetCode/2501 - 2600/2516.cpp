// 2516. Take K of Each Character From Left and Right

// Solution 1: Brute force
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k == 0) return 0;
        int n = s.size(), res = n;
        vector<int> cnt(3, 0);
        for(int i = 0; i < n;i++)
            cnt[s[i] - 'a']++;
        if(cnt[0] < k || cnt[1] < k || cnt[2] < k) return -1;
        vector<int> left(3, 0);
        for(int i = -1; i < n;i++){
            if(i != -1) left[s[i] - 'a']++;
            vector<int> right = left;
            for(int r = n-1; r >= i;r--){
                if(right[0] >= k && right[1] >= k && right[2] >= k){
                    res = min(res, right[0] + right[1] + right[2]);
                    break;
                }
                right[s[r] - 'a']++;
            }
        }
        return res;
    }
};

// Solution 2: Greedy and 2 pointers
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k==0) return 0;
        int n = s.size();
        vector<int> totalCount(3, 0);
        for (char c : s) 
            totalCount[c - 'a']++;
        if (totalCount[0] < k || totalCount[1] < k || totalCount[2] < k) 
            return -1;
        int l = 0, maxLength = 0;
        vector<int> currCount(3, 0);
        for (int r = 0; r < n; r++) {
            currCount[s[r] - 'a']++;
            while (l <= r && (totalCount[0] - currCount[0] < k || totalCount[1] - currCount[1] < k ||
                    totalCount[2] - currCount[2] < k)) {
                currCount[s[l] - 'a']--;
                l++;
            }
            maxLength = max(maxLength, r - l + 1);
        }
        return n - maxLength; 
    }
};