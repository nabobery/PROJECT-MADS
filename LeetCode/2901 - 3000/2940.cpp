// 2940. Find Building Where Alice and Bob Can Meet

// Solution 1: Using DP, Monotonic Stack and Binary Search
// Time Complexity: O(qlogn)
// Space Complexity: O(n+q) 
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        // Initialize the result vector with -1
        vector<int> result(queries.size(), -1);
        // Create a vector of pairs to store the queries which can't be answered immediately
        vector<vector<pair<int, int>>> newQueries(heights.size());
        // Create a monotonic stack to store the heights
        vector<pair<int, int>> monoStack;

        // Iterate through the queries
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            // Swap a and b if a is greater than b
            if (a > b) swap(a, b);
            // If the height of b is greater than the height of a or a is equal to b, they can meet at b
            if (heights[b] > heights[a] || a == b)
                result[i] = b;
            // If the height of b is less than the height of a, store the query in the newQueries vector
            else
                newQueries[b].push_back({heights[a], i});
        }

        // Iterate through the heights in reverse order
        for (int i = heights.size() - 1; i >= 0; i--) {
            // Iterate through the queries in the newQueries vector for a, index
            int monoStackSize = monoStack.size();
            for (auto& [a, b] : newQueries[i]) {
                // Find the position of building greater than height of a in the monoStack
                int position = search(a, monoStack);
                // If the position is valid, update the result vector
                if (position < monoStackSize && position >= 0)
                    result[b] = monoStack[position].second;
            }
            // If the height of the current building is greater than the height of the last building in the monoStack, pop the last building
            while (!monoStack.empty() && monoStack.back().first <= heights[i])
                monoStack.pop_back();
            // Push the current building to the monoStack
            monoStack.push_back({heights[i], i});
        }
        // Return the result vector
        return result;
    }

private:
    // Binary Search Function to find the position of the building greater than height in the monoStack
    int search(int height, vector<pair<int, int>>& monoStack) {
        int left = 0;
        int right = monoStack.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (monoStack[mid].first > height) {
                ans = max(ans, mid);
                left = mid + 1;
            } else
                right = mid - 1;
        }
        return ans;
    }
};