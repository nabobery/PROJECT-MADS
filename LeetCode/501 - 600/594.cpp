// 594. Longest Harmonious Subsequence

// Solution 1 Using Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        unordered_map<int,int> cnt;
        for(int& num: nums) cnt[num]++; 
        for(auto& it : cnt){
            if(cnt.count(it.first+1)) res = max(res, it.second + cnt[it.first+1]);
            if(cnt.count(it.first-1)) res = max(res, it.second + cnt[it.first-1]);
        }
        return res;
    }
};