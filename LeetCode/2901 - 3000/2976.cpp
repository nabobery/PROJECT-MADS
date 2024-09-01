// 2976. Minimum Cost to Convert String I

// Solution 1 using Floyd-Warshall Algorithm
// Time complexity: O(n^3)
// Space complexity: O(1)
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> dist(26, vector<int>(26, INT_MAX));
        long long res = 0;
        for(int i = 0; i < 26;i++) dist[i][i] = 0;
        int n = original.size();
        for(int i = 0; i < n;i++){
            int orig = original[i] - 'a', chang = changed[i] - 'a';
            dist[orig][chang] = min(cost[i], dist[orig][chang]);
        }
        for(int k = 0; k < 26;k++)
            for(int i = 0; i < 26;i++)
                for(int j = 0; j < 26;j++)
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > (dist[i][k] + dist[k][j]))
                        dist[i][j] = dist[i][k] + dist[k][j];
        n = source.size();
        for(int i = 0; i < n;i++){
            if(dist[source[i] - 'a'][target[i] - 'a'] == INT_MAX) return -1;
            res += dist[source[i] - 'a'][target[i] - 'a'];
        }
        return res;
    }
};

