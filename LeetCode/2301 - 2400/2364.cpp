// 2364. Count Number of Bad Pairs

// Solution 1: Using Hashmap and counting
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        // counting all pairs
        long long n = nums.size(), res = (n * (n - 1)) / 2;
        unordered_map<int, int> mp;
        // counting all good pairs and subtracting from total pairs to get bad pairs
        for (int i = 0; i < n; i++)
        {
            mp[nums[i] - i]++;
            res -= (mp[nums[i] - i] - 1);
        }
        return res;
    }
};