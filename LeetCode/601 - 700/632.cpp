// 632. Smallest Range Covering Elements from K Lists

// Solution 1 using Multiset and Sliding Window
// The idea is to use a multiset to store the smallest and largest elements of each list and keep track of the range of the current window.
// and keep removing the smallest element from the multiset and adding the next element from the list of the removed element.
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    void storeSmallerRange(vector<int>& curr, int& start, int& end){
        int l1 = curr[1] - curr[0], l2 = end - start;
        if(l2 < l1 || (l2 == l1 && start < curr[0])){
            curr[0] = start;
            curr[1] = end;
        }
    }
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<int> res(2), p(k, 0);
        res[0] = -1e5; res[1] = 1e5;
        multiset<pair<int,int>> s;
        for(int i = 0; i < k;i++) s.insert({nums[i][0], i});
        while(s.size() == k){
            auto it1 = s.begin();
            auto it2 = s.rbegin();
            int mi = it1->first, mx = it2->first, i = it1->second, j = it2->second;
            storeSmallerRange(res, mi, mx);
            if(res[1] - res[0] == 0) break;
            if(p[i] < nums[i].size() - 1){
                p[i]++;
                s.insert({nums[i][p[i]], i});
            }
            s.erase(it1);
        }
        return res;
    }
};
