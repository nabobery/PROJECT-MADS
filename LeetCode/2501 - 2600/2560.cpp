// 2560. House Robber IV

// Solution 1: using Binary Search
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
class Solution {
    public:
        bool check(vector<int>& nums, int k, int cap){
            int houses = 0, i = 0;
            for(; i < nums.size();){
                if(nums[i] <= cap){
                    houses++;
                    i++;
                }
                i++;
            }
            return houses >= k;
        }
        int minCapability(vector<int>& nums, int k) {
            auto result = minmax_element(nums.begin(), nums.end());
            int l = *result.first, r = *result.second;
            int res = r;
            while(l <= r){
                int mid = (l+ r) /2;
                if(check(nums, k, mid)){
                    res = min(res, mid);
                    r = mid-1;
                }
                else l = mid+1;
            }
            return res;
        }
};