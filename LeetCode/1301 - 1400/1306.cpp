// 1306. Jump Game III
// O(n) space and time
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