// 2127. Maximum Employees to Be Invited to a Meeting

// Solution 1 using Topological Sort
// Time Complexity: O(n)
// Space Complexity: O(n)
// The idea is to create a graph where each person is connected to their favorite person.
// Then, we can find the longest chain in the graph using topological sort or by combining 2 length cycle chains with a mutual pair.
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        // make a directed reversed graph (favourite person -> person)
        vector<vector<int>> reversedGraph(n);
        for (int person = 0; person < n; ++person) {
            reversedGraph[favorite[person]].push_back(person);
        }

        // Helper BFS function to calculate the longest chain leading to a node, excluding certain nodes
        auto bfs = [&](int startNode, unordered_set<int>& visitedNodes) -> int {
            queue<pair<int, int>> q;
            q.push({startNode, 0});
            int maxDistance = 0;
            while (!q.empty()) {
                auto [currentNode, currentDistance] = q.front();
                q.pop();
                for (int neighbor : reversedGraph[currentNode]) {
                    if (visitedNodes.count(neighbor)) continue;
                    visitedNodes.insert(neighbor);
                    q.push({neighbor, currentDistance + 1});
                    maxDistance = max(maxDistance, currentDistance + 1);
                }
            }
            return maxDistance;
        };

        int longestCycle = 0, twoCycleInvitations = 0;
        vector<bool> visited(n, false);

        // Find all cycles and calculate the longest cycle and handle mutual pairs
        for (int person = 0; person < n; ++person) {
            if (!visited[person]) {
                unordered_map<int, int> visitTracker;
                int current = person;
                int steps = 0;
                while (true) {
                    if (visited[current]) break;
                    visited[current] = true;
                    visitTracker[current] = steps++;
                    int nextPerson = favorite[current];
                    if (visitTracker.find(nextPerson) != visitTracker.end()) { // Cycle detected
                        int cycleLength = steps - visitTracker[nextPerson];
                        longestCycle = max(longestCycle, cycleLength);
                        if (cycleLength == 2) { // Mutual pair
                            unordered_set<int> visitedNodes = {current, nextPerson};
                            int chainA = bfs(current, visitedNodes);
                            int chainB = bfs(nextPerson, visitedNodes);
                            twoCycleInvitations += 2 + chainA + chainB;
                        }
                        break;
                    }
                    current = nextPerson;
                }
            }
        }
        // the answer is the maximum between the longest cycle and the two-cycle invitations
        return max(longestCycle, twoCycleInvitations);
    }
};