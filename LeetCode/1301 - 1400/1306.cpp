// 1306. Jump Game III

// Simple BFS
// Time complexity: O(n)
// Space complexity: O(n)
// The idea is to start from the given index and keep adding the indices that can be reached from the current index to the queue.
// We also keep a visited array to avoid visiting the same index again.
// If we reach an index with value 0, we return true.
// If we have visited all the indices and still haven't reached an index with value 0, we return false.
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue <int> q;
        q.push(start);
        vector <bool> visited(n);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(arr[curr] == 0)
                return true;
            if(visited[curr])
                continue;
            if(curr - arr[curr] >= 0)
                q.push(curr - arr[curr]);
            if(curr + arr[curr] < n)
                q.push(curr + arr[curr]);
            visited[curr] = true;
        }
        return false;
    }
};