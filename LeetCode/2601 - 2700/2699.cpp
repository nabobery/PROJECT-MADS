// 2699. Modify Graph Edge Weights

// Solution 1: Dijkstra's Algorithm using Priority Queue
// Time Complexity: O(v*(v+e)*log(v))
// Space Complexity: O(v+e)
class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        // Create adjacency list
        vector<vector<pair<int, int>>> adjacencyList(n);
        for (int i = 0; i < edges.size(); i++) {
            int nodeA = edges[i][0], nodeB = edges[i][1];
            adjacencyList[nodeA].emplace_back(nodeB, i);
            adjacencyList[nodeB].emplace_back(nodeA, i);
        }
        // Initialize distances
        vector<vector<int>> distances(n, vector<int>(2, INT_MAX));
        // Set source distance to 0
        distances[source][0] = distances[source][1] = 0;
        // Initial Dijkstra's Algorithm run
        runDijkstra(adjacencyList, edges, distances, source, 0, 0);
        // If the shortest distance is more than target, return empty vector
        int difference = target - distances[destination][0];
        if (difference < 0) return {}; 
        // Second Dijkstra's Algorithm run
        runDijkstra(adjacencyList, edges, distances, source, difference, 1);
        // If the distance is less than target, return empty vector
        if (distances[destination][1] < target) return {}; 
        // Set the weight of the edges with -1 to 1
        for (auto& edge : edges) {
            if (edge[2] == -1) edge[2] = 1;
        }
        // Return the modified edges
        return edges;
    }

private:
    // Dijkstra's Algorithm
    void runDijkstra(const vector<vector<pair<int, int>>>& adjacencyList, vector<vector<int>>& edges, vector<vector<int>>& distances, int source, int difference, int run) {
        int n = adjacencyList.size();
        // Priority Queue to store {distance, node} (min-heap)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> priorityQueue;
        // Push source node to priority queue
        priorityQueue.push({0, source});
        // Set source distance to 0
        distances[source][run] = 0;
        // Run Dijkstra's Algorithm
        while (!priorityQueue.empty()) {
            // Get the node with minimum distance
            auto [currentDistance, currentNode] = priorityQueue.top();
            priorityQueue.pop();
            // If the distance is greater than the current distance, skip
            if (currentDistance > distances[currentNode][run]) continue;
            // Traverse all the neighbors of the current node
            for (auto& neighbor : adjacencyList[currentNode]) {
                int nextNode = neighbor.first, edgeIndex = neighbor.second;
                // Get the weight of the edge
                int weight = edges[edgeIndex][2];
                // If the weight is -1, set it to 1 (default weight)
                if (weight == -1) weight = 1; 
                // if it is the second run and the weight is -1, calculate the new weight
                if (run == 1 && edges[edgeIndex][2] == -1) {
                    // Calculate the new weight of the edge by adding the difference and get the prev weight of the edge by subtracting the distance of the current node at run 0 and adding the distance of the next node at run 1
                    int newWeight = difference + distances[nextNode][0] - distances[currentNode][1];
                    // If the new weight is greater than the current weight, update the weight
                    if (newWeight > weight) {
                        edges[edgeIndex][2] = weight = newWeight;
                    }
                }
                // If the new distance is less than the current distance, update the distance
                if (distances[nextNode][run] > distances[currentNode][run] + weight) {
                    // Update the distance
                    distances[nextNode][run] = distances[currentNode][run] + weight;
                    // Push the node to the priority queue
                    priorityQueue.push({distances[nextNode][run], nextNode});
                }
            }
        }
    }
};