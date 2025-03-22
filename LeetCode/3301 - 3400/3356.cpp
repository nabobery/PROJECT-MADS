// 3356. Zero Array Transformation II

// Solution 1: Using Binary Search and diff prefix sum
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
// Idea: We can use binary search to find the minimum number of queries needed to form a zero array.
// We can use a diff prefix sum array to keep track of the changes in the array due to the queries.
// We can then iterate over the array and check if the cumulative sum is greater than the element at that index.
// If it is, then we can return false, otherwise we can return true.
// We can then use binary search to find the minimum number of queries needed to form a zero array.
class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int left = 0, right = queries.size();
            if (!canFormZeroArray(nums, queries, right))
                return -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (canFormZeroArray(nums, queries, mid))
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            return left;
        }
    
    private:
        bool canFormZeroArray(vector<int>& nums, vector<vector<int>>& queries,
                              int k) {
            int cumulative = 0;
            vector<int> diff(nums.size() + 1, 0);
            for (int i = 0; i < k; ++i) {
                int start = queries[i][0], end = queries[i][1], val = queries[i][2];
                diff[start] += val;
                diff[end + 1] -= val;
            }
            for (int i = 0; i < nums.size(); ++i) {
                cumulative += diff[i];
                if (cumulative < nums[i])
                    return false;
            }
            return true;
        }
    };