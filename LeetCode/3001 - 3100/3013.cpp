// 3013. Divide an Array Into Subarrays With Minimum Cost II

// Solution 1: Using Two Multisets to Maintain Sliding Window
// Time Complexity: O(n log k)
// Space Complexity: O(k)
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size(), target = k - 1;
        long long curr = 0;
        // Two multisets to maintain the k-1 smallest elements
        multiset<int> left, right;

        // Function to balance the two multisets
        auto balance = [&]() {
            // Ensure left has exactly target elements
            while (left.size() < target && !right.empty()) {
                int val = *right.begin();
                curr += val;
                left.insert(val);
                right.erase(right.begin());
            }
            // Remove excess elements from left
            while (left.size() > target) {
                int val = *left.rbegin();
                curr -= val;
                right.insert(val);
                left.erase(prev(left.end()));
            }
            // Swap elements to maintain order
            if (!left.empty() && !right.empty() && *left.rbegin() > *right.begin()) {
                int l_val = *left.rbegin();
                int r_val = *right.begin();
                curr = curr - l_val + r_val;
                left.erase(prev(left.end()));
                right.erase(right.begin());
                left.insert(r_val);
                right.insert(l_val);
            }
        };

        // Initialize the first window
        for (int i = 1; i <= dist + 1 && i < n; ++i) {
            right.insert(nums[i]);
        }
        // Balance the multisets for the first window
        balance();

        // Calculate initial cost
        long long minCost = (long long)nums[0] + curr;
        // Slide the window across the array
        for (int i = dist + 2; i < n; ++i) {
            int toRemove = nums[i - dist - 1];
            auto it = left.find(toRemove);
            if (it != left.end()) {
                curr -= toRemove;
                left.erase(it);
            } else {
                right.erase(right.find(toRemove));
            }

            right.insert(nums[i]);
            balance();
            // Update minimum cost
            minCost = min(minCost, (long long)nums[0] + curr);
        }

        return minCost;
    }
};