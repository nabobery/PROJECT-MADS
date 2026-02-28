// 3666. Minimum Operations to Equalize Binary String

// Solution 1: Using BFS and going from the number of zeroes to 0 -> TLE
// Time Complexity: O(n^2) in the worst case, where n is the length
// Space Complexity: O(n)

// Observations:
// Suppose we're flipping i zeroes to ones and k - i ones to zeroes in one operation, then the number of zeroes in the string will change by k - 2 * i.
// z` = z + k - 2 * i, where z is the current number of zeroes in the string and z` is the number of zeroes after performing the operation.
// which means z+k will have the same parity as z, z%2 == (z+k)%2
// Also, i will be range of [max(0, k - (n - z)), min(z, k)], which means z` will be in the range of [z + k - 2 * min(z, k), z + k - 2 * max(0, k - (n - z))] = [z + k - 2 * min(z, k), z + k - 2 * max(0, k - (n - z))]

class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length(), zeroes = 0;
        // Count the number of zeroes in the string
        for (char c : s)
            if (c == '0')
                zeroes++;
        if (zeroes == 0)
            return 0;
        // dist[i] will store the minimum number of operations required to have i zeroes in the string
        vector<int> dist(n + 1, -1);
        // BFS to find the minimum operations to reach 0 zeroes
        queue<int> q;
        dist[zeroes] = 0;
        q.push(zeroes);
        while (!q.empty()) {
            int z = q.front();
            q.pop();
            // Calculate the range of next possible zero counts after performing one operation
            int i_min = max(0, k - (n - z)), i_max = min(z, k);
            // The next possible zero counts can be calculated based on the number of zeroes we can flip to ones and the number of ones we can flip to zeroes in one operation
            int z_min = z + k - 2 * i_max, z_max = z + k - 2 * i_min;
            // We can only flip an even number of zeroes to ones and an even number of ones to zeroes, so we iterate through the possible next zero counts in steps of 2
            for (int next_z = z_min; next_z <= z_max; next_z += 2) {
                if (dist[next_z] == -1) {
                    dist[next_z] = dist[z] + 1;
                    // If we have reached 0 zeroes, we can return the number of operations required
                    if (next_z == 0)
                        return dist[next_z];
                    q.push(next_z);
                }
            }
        }
        // If we exhaust the queue without reaching 0 zeroes, it means it's not possible to equalize the string, so we return -1
        return -1;
    }
};

// Solution 2: Using BFS and only traversing the unvisited zero counts -> Accepted
// Time Complexity: O(n log n) in the worst case, where n is the length of the string
// Space Complexity: O(n)
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length(), zeroes = 0;
        for (char c : s) if (c == '0') zeroes++;
        if (zeroes == 0) return 0;
        set<int> unvisited[2];
        for (int i = 0; i <= n; ++i) unvisited[i % 2].insert(i);

        vector<int> dist(n + 1, -1);
        queue<int> q;
        dist[zeroes] = 0;
        unvisited[zeroes % 2].erase(zeroes);
        q.push(zeroes);
        while (!q.empty()) {
            int z = q.front();
            q.pop();
            int i_min = max(0, k - (n - z)), i_max = min(z, k);
            int z_min = z + k - 2 * i_max, z_max = z + k - 2 * i_min;

            auto& target_set = unvisited[(z + k) % 2];
            auto it = target_set.lower_bound(z_min);

            while (it != target_set.end() && *it <= z_max) {
                int next_z = *it;
                dist[next_z] = dist[z] + 1;
                if (next_z == 0) return dist[next_z];
                
                q.push(next_z);
                it = target_set.erase(it);
            }
        }
        return -1;
    }
};