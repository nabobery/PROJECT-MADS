// 992. Subarrays with K Different Integers

// Naive Solution 1
// Time Complexity: O(n^2)
// Space Complexity: O(n)
// For each i, find the number of subarrays that have exactly K different integers
class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int res = 0, n = nums.size();
        for (int l = 0; l < n; l++)
        {
            unordered_set<int> s;
            for (int r = l; r < n; r++)
            {
                s.insert(nums[r]);
                if (s.size() == k)
                    res++;
            }
        }
        return res;
    }
};

// Solution 2 using Two Pointers
// Number of subarrays with exactly K distinct integers = Number of subarrays with at most K distinct integers - Number of subarrays with at most K-1 distinct integers
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k){
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
    // function to find the number of subarrays with at most K distinct integers
    int atMostKDistinct(vector<int> &nums, int k)
    {
        // res stores the number of subarrays with at most K distinct integers
        int res = 0, n = nums.size();
        // m stores the frequency of each integer in the current window
        unordered_map<int, int> m;
        // l and r are the left and right pointers of the window
        for (int l = 0, r = 0; r < n; r++)
        {
            // if the frequency of nums[r] is 0, then it is a new integer
            if (m[nums[r]]++ == 0)
                k--;
            // if the number of distinct integers in the current window is greater than K
            while (k < 0)
            {
                // if the frequency of nums[l] is 1, then it is the last occurrence of nums[l]
                if (--m[nums[l]] == 0)
                    k++;
                // move the left pointer to the right
                l++;
            }
            // add the number of subarrays with at most K distinct integers
            res += r - l + 1;
        }
        return res;
    }
};

