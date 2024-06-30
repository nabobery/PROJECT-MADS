// 1791. Find Center of Star Graph

// Solution 1 using degree array
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> degree(n, 0);
        for(auto edge: edges){
            degree[edge[0]-1]++;
            degree[edge[1]-1]++;
        }
        for(int i = 0; i < n;i++) if(degree[i] == n-1) return i+1;
        return -1;
    }
};

// Solution 2 using boolean array
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<bool> degree(n, false);
        for(auto edge: edges){
            if(!degree[edge[0]-1]) degree[edge[0]-1] = true;
            else return edge[0];
            if(!degree[edge[1]-1]) degree[edge[1]-1] = true;
            else return edge[1];
        }
        return -1;
    }
};

// Solution 3 using set
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int> degree;
        for(auto edge: edges){
            if(!degree.count(edge[0])) degree.insert(edge[0]);
            else return edge[0];
            if(!degree.count(edge[1])) degree.insert(edge[1]);
            else return edge[1];
        }
        return -1;
    }
};