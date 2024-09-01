// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

// Solution 1: Floyd-Warshall Algorithm
// Time complexity: O(n^3)
// Space complexity: O(n^2)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(int i = 0; i < n;i++) dist[i][i] = 0;
        for(auto edge: edges){
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        for(int k = 0; k < n;k++)
            for(int i = 0; i < n;i++)
                for(int j = 0; j < n;j++)
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > (dist[i][k] + dist[k][j]))
                        dist[i][j] = dist[i][k] + dist[k][j];
        int mi = n, res = -1;
        for(int i = 0; i < n;i++){
            int curr = 0;
            for(int j = 0; j < n;j++)
                if(dist[i][j] <= distanceThreshold) curr++;
            if(res == -1 || curr == mi) res = i;
            if(curr < mi){
                mi = curr;
                res = i;
            }
        }
        return res;
    }
};

// Solution 2: Dijkstra Algorithm
// Time complexity: O(n^2logn)
// Space complexity: O(n^2)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto edge: edges){
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        int res = -1, mi = n;
        for(int i = 0; i < n;i++){
            vector<int> dist(n, INT_MAX);
            dist[i] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, i});
            while(!pq.empty()){
                auto [d, u] = pq.top();
                pq.pop();
                if(d > dist[u]) continue;
                for(auto [v, w]: graph[u]){
                    if(dist[v] > dist[u] + w){
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            int curr = 0;
            for(int j = 0; j < n;j++)
                if(dist[j] <= distanceThreshold) curr++;
            if(res == -1 || curr == mi) res = i;
            if(curr < mi){
                mi = curr;
                res = i;
            }
        }
        return res;
    }
};