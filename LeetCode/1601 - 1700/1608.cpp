// 1608. Special Array With X Elements Greater Than or Equal X

// Solution 1 Simple and Easy using Sorting and Binary Search
// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= n;i++){
            auto it = lower_bound(nums.begin(), nums.end(), i) - nums.begin();
            if(it == n-i) return i;
        }
        return -1;
    }
};
