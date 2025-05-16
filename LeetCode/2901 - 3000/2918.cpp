// 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros

// Solution 1 using Greedy Appproach
// Time Complexity: O(n) where n is the number of elements in the array
// Space Complexity: O(1)
class Solution
{
public:
    long long minSum(const vector<int> &nums1, const vector<int> &nums2)
    {
        long long s1 = accumulate(nums1.begin(), nums1.end(), 0LL),
                  s2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        int z1 = count(nums1.begin(), nums1.end(), 0),
            z2 = count(nums2.begin(), nums2.end(), 0);
        long long c1 = s1 + z1, c2 = s2 + z2;

        if (z1 == 0 && z2 == 0)
            return (s1 == s2) ? s1 : -1;
        if (z1 > 0 && z2 > 0)
            return max(c1, c2);
        if (z1 == 0)
            return (s1 >= c2) ? s1 : -1;
        return (s2 >= c1) ? s2 : -1;
    }
};