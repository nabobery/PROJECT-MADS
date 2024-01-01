// 455. Assign Cookies

// Solution 1: Greedy + Two Pointers
// Time Complexity: O(nlogn)
// Space Complexity: O(log⁡m+log⁡n)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0, p = 0, n = s.size();
        for(auto greed : g){
            while(p < n && s[p] < greed) p++;
            if(p < n){
                res++;
                p++;
            }
            else break;
        }
        return res;
    }
};