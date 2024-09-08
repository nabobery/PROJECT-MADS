// 719. Find K-th Smallest Pair Distance

// Solution 1 using binary search
// Time complexity: O(nlogn + nlognlogn)
// Space complexity: O(1)
class Solution {
public:
    int helper(vector<int>& nums, int mid){
        int res = 0, n = nums.size(), j = 0;
        for(int i = 0; i < n;i++){
            while(j < n && (nums[j] - nums[i]) <= mid) j++;
            res += (j-i-1);
        }
        return res;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums[0], result = l;
        while(l <= r){
            int mid = (l+r)/2;
            if(helper(nums,mid) >= k){
                result = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return result;
    }
};

// Solution 2 using efficient binary search
// Time complexity: O(nlogn + nlognlogn)
// Space complexity: O(1)
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, r = nums.back() - nums[0];
        while(l < r){
            int mid = (l+r)/2, cnt = 0;
            for(int i = 0, j = 0; i < n;i++){
                while(j < n && nums[j] - nums[i] <= mid) j++;
                cnt += j-i-1;
            }
            if(cnt < k) l = mid+1;
            else r = mid;
        }
        return l;
    }
};