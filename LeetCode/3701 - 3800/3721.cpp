// 3721. Longest Balanced Subarray II
//
// Problem: Find the longest subarray where distinct even count == distinct odd count
//
// Solution: Using Sweep Line Algorithm + Segment Tree with Lazy Propagation
// Time Complexity: O(n log n)
// Space Complexity: O(n)
//
// Key Algorithm Concepts:
// 1. Assign each number: +1 if odd, -1 if even (based on parity count diff)
// 2. A balanced subarray [i,j] has sum = 0 (equal even and odd counts)
// 3. Use Sweep Line: process elements left to right and find longest subarray with sum 0
// 4. Segment Tree: tracks min/max values in range to efficiently find first zero point
// 5. Coordinate Compression: map unique values to compressed indices for sparse arrays

class Solution
{
    vector<int> tree_min; // Segment tree for tracking minimum values
    vector<int> tree_max; // Segment tree for tracking maximum values
    vector<int> lazy;     // Lazy propagation array for range updates
    int n;                // Size of the array

    // Push lazy updates from parent node to children (Lazy Propagation)
    // This ensures updates are applied only when needed (on query)
    void push(int node)
    {
        if (lazy[node] != 0)
        {
            int left = 2 * node;
            int right = 2 * node + 1;

            // Apply lazy value to both children
            tree_min[left] += lazy[node];
            tree_max[left] += lazy[node];
            lazy[left] += lazy[node];

            tree_min[right] += lazy[node];
            tree_max[right] += lazy[node];
            lazy[right] += lazy[node];

            // Clear current node's lazy value
            lazy[node] = 0;
        }
    }

    // Range Update: add 'val' to all elements in range [l, r]
    // This is done in O(log n) using lazy propagation
    void update(int node, int start, int end, int l, int r, int val)
    {
        // Current range doesn't overlap with update range
        if (l > end || r < start)
            return;

        // Current range is completely within update range - update this node
        if (l <= start && end <= r)
        {
            tree_min[node] += val;
            tree_max[node] += val;
            lazy[node] += val;
            return;
        }

        // Partial overlap - propagate lazy value and recurse on children
        push(node);
        int mid = (start + end) / 2;

        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);

        // Update current node's min/max from children
        tree_min[node] = min(tree_min[2 * node], tree_min[2 * node + 1]);
        tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
    }

    // Query: find the leftmost index in range [start, end] where value equals 0
    // This finds the first balanced point from left
    int queryFirstZero(int node, int start, int end)
    {
        // If all values in this range are > 0 or all < 0, no zero exists
        if (tree_min[node] > 0 || tree_max[node] < 0)
            return -1;

        // Base case: single element node
        if (start == end)
        {
            return tree_min[node] == 0 ? start : -1;
        }

        // Push any lazy updates before continuing
        push(node);
        int mid = (start + end) / 2;

        // Search left subtree first (we want leftmost zero)
        int res = queryFirstZero(2 * node, start, mid);
        if (res != -1)
            return res;

        // If not found in left, search right subtree
        return queryFirstZero(2 * node + 1, mid + 1, end);
    }

public:
    // Main function: Find longest balanced subarray
    // Approach: For each position, track when balance becomes 0 (equal even/odd)
    int longestBalanced(vector<int> &nums)
    {
        int sz = nums.size();
        n = sz;

        // Initialize segment tree and lazy arrays
        tree_min.assign(4 * n, 0);
        tree_max.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        // COORDINATE COMPRESSION:
        // Compress unique values in array to avoid sparse segment tree
        // This optimizes space when values might be very large
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        sorted_nums.erase(unique(sorted_nums.begin(), sorted_nums.end()), sorted_nums.end());

        // Map each unique number to its last known position
        // This helps track when we need to update ranges (removing previous occurrences)
        vector<int> last_pos(sorted_nums.size(), -1);

        int max_len = 0;

        // SWEEP LINE: Process each element left to right
        for (int i = 0; i < sz; ++i)
        {
            int raw_val = nums[i];

            // Get compressed index of current value (binary search in sorted array)
            int compressed_val = lower_bound(sorted_nums.begin(), sorted_nums.end(), raw_val) - sorted_nums.begin();

            // Get previous position of this value
            int prev_index = last_pos[compressed_val];

            // Assign +1 for odd, -1 for even
            // This transforms the problem: balanced = subarray with sum 0
            int val = (raw_val % 2 != 0) ? 1 : -1;

            // Update range [prev_index+1, i] with the value
            // This marks all positions between last occurrence and current
            // with their contribution (odd or even)
            update(1, 0, n - 1, prev_index + 1, i, val);

            // Update last known position of this value
            last_pos[compressed_val] = i;

            // Query: find leftmost index where cumulative value = 0
            // This represents a balanced subarray from that index to i
            int l_index = queryFirstZero(1, 0, n - 1);

            // If found a point with 0 sum, calculate subarray length
            if (l_index != -1)
            {
                max_len = max(max_len, i - l_index + 1);
            }
        }

        return max_len;
    }
};