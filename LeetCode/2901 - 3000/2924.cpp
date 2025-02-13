// 2924. Find Champion II

// Solution 1: Using Indegree
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        for(auto& edge: edges)
            indegree[edge[1]]++;
        int res = -1;
        for(int i = 0; i < n;i++){
            if(indegree[i] == 0){
                if(res == -1) res= i;
                else return -1;
            }
        }
        return res;
    }
};