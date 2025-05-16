// 2302. Count Subarrays With Score Less Than K

// Solution 1: Using Smart Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            long long res = 0, sum = 0;
            int l = 0, n = nums.size();
            for(int r = 0; r < n;r++){
                if(r-l > 0) sum = (sum/(r-l))*(r-l+1);
                sum += nums[r]*(long long)(r-l+1);
                while(l <= r && sum >= k){
                    sum -= (long long)(r-l+1)*nums[l];
                    sum /= (r-l+1);
                    sum *= (r-l);
                    l++;
                }
                if(sum < k) res += (r-l+1);
            }
            return res;
        }
};