// 2573. Find the String with LCP

// Solution 1: Using Logical Deductions and DSU
// Time Complexity: O(n^2)
// Space Complexity: O(n)

// DSU (Disjoint Set Union) class to manage groups of indices that should have the same character
struct DSU {
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py)
            parent[py] = px;
    }
};

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        // Check if the diagonal elements of the LCP matrix are correct
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i)
                return "";
        }
        // Check if the LCP values are consistent with the definition of LCP
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] > 0) {
                    if (i + 1 < n && j + 1 < n) {
                        // If the LCP is greater than 0, then word[i] should be equal to word[j], and the LCP of the next characters should be one less than the current LCP
                        if (lcp[i][j] != lcp[i + 1][j + 1] + 1)
                            return "";
                    } else {
                        // If we are at the end of the string, the LCP should be 1 if the characters are the same
                        if (lcp[i][j] != 1)
                            return "";
                    }
                }
            }
        }
        // Use DSU to group indices that should have the same character based on the LCP values
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If the LCP is greater than 0, it means that the characters at index i and j should be the same, so we unite their groups in the DSU
                if (lcp[i][j] > 0) {
                    dsu.unite(i, j);
                }
            }
        }
        // Group the indices by their DSU root to determine which indices should have the same character
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[dsu.find(i)].push_back(i);
        }

        // If there are more than 26 groups, it's impossible to assign unique characters to each group, so we return an empty string
        if (groups.size() > 26)
            return "";

        // Assign characters to each group of indices. We start with 'a' (to get lexicographically smallest result) and assign the same character to all indices in the same group.
        vector<char> res(n, 0);
        char curr = 'a';

        // Iterate through each index and assign characters based on their DSU groups. If a group has not been assigned a character yet, we assign the current character to all indices in that group and move to the next character.
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            if (res[i] == 0) {
                if (curr > 'z')
                    return "";

                for (int idx : groups[root]) {
                    res[idx] = curr;
                }
                curr++;
            }
        }
        // After assigning characters, we need to verify that the assigned characters satisfy the LCP conditions. We check if any two indices that have an LCP of 0 are assigned the same character, which would violate the LCP condition.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] == 0) {
                    if (res[i] == res[j])
                        return "";
                }
            }
        }
        // If all conditions are satisfied, we convert the character vector to a string and return it as the result.
        return string(res.begin(), res.end());
    }
};