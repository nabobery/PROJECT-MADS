// 1722. Minimize Hamming Distance After Swap Operations

// Solution 1: Union-Find + Hash Map
// Time Complexity: O(n + m), where n is the length of source and target, and m is the number of allowedSwaps.
// Space Complexity: O(n), for the parent array and the hash map.
class Solution {
public:
    vector<int> parent;

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j)
            parent[root_i] = root_j;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        // Initialize the parent array for union-find from 0 to n-1
        iota(parent.begin(), parent.end(), 0);
        
        // Union the indices based on allowedSwaps (i.e., connect the indices that can be swapped)
        for (const auto& s : allowedSwaps) {
            unite(s[0], s[1]);
        }

        // Group indices by their root parent to identify connected components
        unordered_map<int, vector<int>> components;
        for (int i = 0; i < n; ++i) {
            components[find(i)].push_back(i);
        }

        int res = 0;

        // For each connected component, count the frequency of elements in source and target,
        for (auto& [root, indices] : components) {
            unordered_map<int, int> counts;
            for (int idx : indices) {
                counts[source[idx]]++;
            }

            // Compare the counts with the corresponding elements in target for the same indices
            for (int idx : indices) {
                // If the element in target can be matched with an element in source (i.e., counts > 0), decrease the count.
                if (counts[target[idx]] > 0) {
                    counts[target[idx]]--;
                // If it cannot be matched, it contributes to the Hamming distance.
                } else {
                    res++;
                }
            }
        }
        // Return the total Hamming distance after considering all connected components.
        return res;
    }
};