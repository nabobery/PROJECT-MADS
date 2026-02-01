// 3510. Minimum Pair Removal to Sort Array II

// Solution: Using a Min-Heap to Merge Pairs, Track Violations and update using DLL
// Time Complexity: O(N log N)
// Space Complexity: O(N)
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int violations = 0, n = nums.size(), res = 0;
        // Doubly Linked List to track active neighbors
        vector<int> L(n), R(n);
        for (int i = 0; i < n; i++) {
            L[i] = i - 1;
            R[i] = i + 1;
        }
        // Track active elements
        vector<bool> active(n, true);

        // Use long to avoid overflow
        vector<long> a(nums.begin(), nums.end());

        // check if the current index is a violation
        // i.e., a[i] > a[R[i]] i.e., descending order
        auto isViolation = [&](int idx) {
            if (idx < 0 || R[idx] >= n)
                return false;
            return a[idx] > a[R[idx]];
        };

        // Initial count of violations
        for (int i = 0; i < n - 1; i++) {
            if (isViolation(i))
                violations++;
        }

        // Min-Heap to store sums of adjacent pairs
        priority_queue<pair<long, int>, vector<pair<long, int>>,
                       greater<pair<long, int>>> pq;

        // Initialize the heap with all adjacent pairs
        for (int i = 0; i < n - 1; i++)
            pq.push({a[i] + a[i + 1], i});

        // Process until no violations remain 
        while (!pq.empty() && violations > 0) {
            // Get the smallest sum pair
            auto [sum, i] = pq.top();
            pq.pop();
            // Get the right neighbor
            int j = R[i];
            // If either is inactive or sum doesn't match, skip
            if (!active[i] || j == n || !active[j] ||
                sum != a[i] + a[j]) {
                continue;
            }
            // Update violations before removing j
            if (isViolation(L[i]))
                violations--;
            // Update violations for i and j
            if (isViolation(i))
                violations--;
            if (isViolation(j))
                violations--;
            // Remove j
            active[j] = false;
            // Update links in DLL and sum at i
            int nextR = R[j];
            R[i] = nextR;
            a[i] = sum;
            // Add new pairs to the heap
            if (L[i] >= 0)
                pq.push({a[i] + a[L[i]], L[i]});
            if (nextR < n) {
                L[nextR] = i;
                pq.push({a[i] + a[R[i]], i});
            }
            // Update violations after removal
            if (isViolation(L[i]))
                violations++;
            if (isViolation(i))
                violations++;
            // Increment removal count
            res++;
        }
        return res;
    }
};