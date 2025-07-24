// 2616. Minimize the Maximum Difference of Pairs

// Solution 1: Greedy Approach using Sorting and Binary Search
// Time Complexity: O(n log n)
// Space Complexity: O(n)
class Solution {
public:
    // Greedy Helper function to check if we can form at least p pairs with a maximum difference of mx
    // between the elements of each pair
    bool check(int mx, vector<int>& nums, int p){
        int cnt = 0, n = nums.size();
        for(int i = 0; i < n-1;i++){
            if(abs(nums[i] - nums[i+1]) <= mx){
                cnt++;
                i++;
            }
        }
        return cnt >= p;
    }
    // Main function to minimize the maximum difference of pairs
    int minimizeMax(vector<int>& nums, int p) {
        // If p is 0, we can return 0 as no pairs need to be formed
        if(p == 0) return 0;
        int n = nums.size(), res = 0;
        // Sort the array to facilitate pair formation
        sort(nums.begin(), nums.end());
        // Binary search to find the minimum maximum difference
        int l = 0, r = nums[n-1] - nums[0];
        while(l <= r){
            int mid = (l+r)/2;
            if(check(mid, nums, p)){
                res= mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return res;
    }
};
