// 1208. Get Equal Substrings Within Budget

// Solution 1 using Sliding Window Technique
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), l = 0, res = 0, curr = 0;
        vector<int> costs(n);
        for(int i = 0; i < n;i++) costs[i] = abs(s[i] - t[i]);
        for(int r = 0; r < n;r++){
            curr += costs[r];
            if(curr <= maxCost) res = max(res, r-l+1);
            else{
                while(l <= r && curr > maxCost){
                    curr -= costs[l];
                    l++;
                }
            }
        }
        return res;
    }
};


// Optimized Solution 1 with Space Complexity O(1)

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), l = 0, res = 0, curr = 0;
        for(int r = 0; r < n;r++){
            curr += abs(s[r] - t[r]);
            if(curr <= maxCost) res = max(res, r-l+1);
            else{
                while(l <= r && curr > maxCost){
                    curr -= abs(s[l] - t[l]);
                    l++;
                }
            }
        }
        return res;
    }
};

// Solution 2 using Prefix Sum and Binary Search
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), res = 0;
        vector<int> costs(n+1);
        for(int i = 0; i < n;i++) costs[i+1] = costs[i] + abs(s[i] - t[i]);
        for(int i = 0; i <= n;i++){
            int l = i, r = n;
            while(l < r){
                int mid = l + (r-l)/2;
                if(costs[mid+1] - costs[i] <= maxCost) l = mid+1;
                else r = mid;
            }
            res = max(res, l-i);
        }
        return res;
    }
};