// 2570. Merge Two 2D Arrays by Summing Values

// Simple Solution using Map
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        vector<vector<int>> res;
        map<int, int> mp;
        for (auto &nums : nums1)
            mp[nums[0]] += nums[1];
        for (auto &nums : nums2)
            mp[nums[0]] += nums[1];
        for (auto &[id, val] : mp)
            res.push_back({id, val});
        return res;
    }
};

// Solution 1 using 2 Pointers
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        vector<vector<int>> res;
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (nums1[i][0] == nums2[j][0])
            {
                res.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
            else if (nums1[i][0] < nums2[j][0])
            {
                res.push_back(nums1[i]);
                i++;
            }
            else
            {
                res.push_back(nums2[j]);
                j++;
            }
        }
        while (i < n)
            res.push_back(nums1[i++]);
        while (j < m)
            res.push_back(nums2[j++]);
        return res;
    }
};