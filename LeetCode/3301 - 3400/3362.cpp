// 3362. Zero Array Transformation III

// Solution 1: Greedy Approach Using Sorting, Priority Queue, and Prefix Sum
// Time Complexity: O(nlogn) where n is the number of elements in the array
// Space Complexity: O(n) where n is the number of elements in the array
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        // Sort the queries based on the first element
        sort(queries.begin(), queries.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        int n = nums.size(), decrement = 0;
        //  a priority queue to store the second element of the queries in descending order
        priority_queue<int> pq;
        // a prefix sum array to keep track of the number of decrements
        vector<int> prefix(n + 1, 0);
        // Iterate through the queries and process them
        for (int i = 0, j = 0; i < n; ++i) {
            // Update the prefix sum array with the decrements
            decrement += prefix[i];
            // Process the queries that have the same first element and update the priority queue
            while (j < queries.size() && queries[j][0] == i) {
                pq.push(queries[j][1]);
                ++j;
            }
            // If the current element is more than decrement, so we need more operations
            // get all operations from the priority queue that can be used 
            // and update the prefix sum array
            // Greedily remove the farthest element from the priority queue
            while (decrement < nums[i] && !pq.empty() && pq.top() >= i) {
                // increase current window decrement
                decrement += 1;
                // decrease the number of operations needed after the window
                prefix[pq.top() + 1] -= 1;
                // remove the top element from the priority queue
                pq.pop();
            }
            // If the current element is still more than decrement, return -1
            if (decrement < nums[i]) 
                return -1;        
        }
        // Return the size of the priority queue, which represents the number of operations not needed
        return pq.size();
    }
};