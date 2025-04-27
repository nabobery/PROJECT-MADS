// 2537. Count the Number of Good Subarrays

// Solution 1: Using Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            long long res = 0;
            unordered_map<int,int> mp;
            int l = 0, currPairs = 0,n = nums.size();
            for(int r = 0; r < n;r++){
                mp[nums[r]]++;
                // Number of Good Pairs = nC2 = n*(n-1)/2
                // Increase = n*(n-1)/2 - (n-1)*(n-2)/2 = n-1
                currPairs += (mp[nums[r]] - 1);
                while(l < r && currPairs >= k){
                    // decrease the number of good pairs
                    currPairs -= (mp[nums[l]] - 1);
                    mp[nums[l]]--;
                    l++;
                    // Add the count of good sub arrays
                    res += (n-r);
                }
            }
            return res;
        }
};