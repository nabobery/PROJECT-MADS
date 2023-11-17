// 2642. Design Graph With Shortest Path Calculator

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */


// Solution 1 by maintaining a distance matrix and djiikstra's algorithm

// Let E be number of edges in the graph when the call to any method is made.
// Let V be the number of vertices in the graph when the call to any method is made.
// Let N be the maximum number of calls made to addEdge.
// Let M be the maximum number of calls made to shortestPath.

// Time complexity: O(N+M(V+ElogV))
// Space complexity: O(V^2+V+N)

class Graph {
public:
    vector<vector<int>> dist;
    Graph(int n, vector<vector<int>>& edges) {
        dist.resize(n, vector<int>(n, -1));
        for(int i = 0; i < n;i++) dist[i][i] = 0;
        for(auto it : edges){
            dist[it[0]][it[1]] = it[2];
        } 
    }
    
    void addEdge(vector<int> edge) {
        dist[edge[0]][edge[1]] = edge[2];
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> mindist(dist.size(), 1e7);
        pq.push(make_pair(0, node1));
        mindist[node1] = 0;
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            for(int i = 0; i < mindist.size();i++){
                if(dist[u][i] != -1){
                    if (mindist[i] > mindist[u] + dist[u][i]) {
                        mindist[i] = mindist[u] + dist[u][i];
                        pq.push(make_pair(mindist[i], i));
                    }
                }
            }
        }
        return (mindist[node2] == 1e7 ? -1 : mindist[node2]);
    }
};


// Solution 2 by maintaining a distance matrix and floyd warshall's algorithm

// Let E be number of edges in the graph when the call to any method is made.
// Let V be the number of vertices in the graph when the call to any method is made.
// Let N be the maximum number of calls made to addEdge.
// Let M be the maximum number of calls made to shortestPath.

// Time complexity: O(M+NV^2+V^3)
// Space complexity: O(V^2)

class Graph {
public:
    vector<vector<int>> dist;
    Graph(int n, vector<vector<int>>& edges) {
        dist.resize(n, vector<int>(n, 1e7));
        for(int i = 0; i < n;i++) dist[i][i] = 0;
        for(auto it : edges){
            dist[it[0]][it[1]] = it[2];
        } 
        for(int i = 0; i < n;i++){
            dist[i][i] = 0;
        }
        for(int k = 0; k < n;k++){
            for(int i = 0; i < n;i++){
                for(int j = 0; j < n;j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    void addEdge(vector<int> edge) {
        int n = dist.size();
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                dist[i][j] = min(dist[i][j], dist[i][edge[0]] + dist[edge[1]][j] + edge[2]);
            }
        }
    }

    int shortestPath(int node1, int node2) {
        return (dist[node1][node2] == 1e7 ? -1 : dist[node1][node2]);
    }
};
    
   
