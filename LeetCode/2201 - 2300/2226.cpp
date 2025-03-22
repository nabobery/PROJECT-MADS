// 2226. Maximum Candies Allocated to K Children

// Solution 1: Using Binary Search
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
class Solution {
    public:
        bool isPossible(vector<int>& candies, long long& k, int currCandy){
            long long piles = 0;
            for(int candy : candies) piles += candy/currCandy;
            return piles >= k;
        }
        int maximumCandies(vector<int>& candies, long long k) {
            int l = 1, r = 1e7;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (isPossible(candies, k, mid))
                    l = mid + 1;
                else
                    r = mid-1;
            }
            return l-1;
        }
};