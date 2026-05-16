// 1345. Jump Game IV

// Solution 1: BFS 
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1)
            return 0;

        // Map each value to the list of indices where it appears
        unordered_map<int, vector<int>> numToIndices;
        for (int i = 0; i < n; i++) {
            numToIndices[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        // Start BFS from the first index
        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int curr = q.front();
                q.pop();

                // If we have reached the last index, return the number of steps taken
                if (curr == n - 1)
                    return steps;

                // Explore neighbors: indices with the same value, and adjacent indices
                vector<int>& neighbors = numToIndices[arr[curr]];
                neighbors.push_back(curr - 1);
                neighbors.push_back(curr + 1);

                for (int next : neighbors) {
                    // Check if the next index is within bounds and not visited
                    if (next >= 0 && next < n && !visited[next]) {
                        // If we have reached the last index, return the number of steps taken + 1
                        if (next == n - 1)
                            return steps + 1;
                        // Mark the next index as visited and add it to the queue
                        visited[next] = true;
                        q.push(next);
                    }
                }
                // Clear the neighbors to prevent future redundant checks
                neighbors.clear();
            }
            // Increment the number of steps after processing all nodes at the current level
            steps++;
        }
        return -1;
    }
};