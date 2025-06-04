// 1298. Maximum Candies You Can Get from Boxes

// Solution 1: Using BFS to explore all possible paths from the initial boxes.
// Time Complexity: O(n), where n is the number of boxes
// Space Complexity: O(n), where n is the number of boxes
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int res = 0, n = status.size();
        queue<int> q;
        vector<int> visited(n, 0);
        for(int& u: initialBoxes){
            if(status[u]) q.push(u);
            visited[u] = 1;
        }
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            if(visited[u] == 2) continue;
            res += candies[u];
            visited[u] = 2;
            for(int& v: containedBoxes[u]){
                if(status[v]) q.push(v); 
                visited[v] = 1;
            }
            for(int& v: keys[u]){
                status[v] = 1;
                if(visited[v] == 1) q.push(v);
            }
        }
        return res;
    }
};