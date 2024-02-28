// 2092. Find All People With Secret

// Solution 1 using Djikstra like Algorithm
// Time complexity: O((n + m)*log(n+m) )
// Space complexity: O(n + m)
typedef pair<int, int> pi; 
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // to store the result
        vector<int> res;
        // to store the visited people who know the secret
        unordered_set<int> s;
        // to store the graph in the form of adjacency list
        unordered_map<int, vector<pi>> adj;
        // add 0 and first person to the graph
        adj[0].push_back({firstPerson, 0});
        adj[firstPerson].push_back({0, 0});
        // add the person and time pairs of the meetings to the graph
        for(auto& meeting : meetings){
            adj[meeting[0]].push_back({meeting[1], meeting[2]});
            adj[meeting[1]].push_back({meeting[0], meeting[2]});
        }
        // priority queue to store the next person to visit based on the time
        priority_queue<pi , vector<pi>, greater<pi> > pq;
        // add 0 time and 0 person to the priority queue
        pq.push({0, 0});
        while(!pq.empty()){
            // get the next person to visit
            auto curr = pq.top();
            pq.pop();
            // if the person is already visited, continue
            if(s.count(curr.second)) continue;
            // add the person to the visited set
            s.insert(curr.second);
            // visit the neighbours of the current person
            for(auto n : adj[curr.second]){
                // if the neighbour is not visited and the time for the secret to reach the neighbour is greater or equal than the time for the current person, add the neighbour to the priority queue
                if(curr.first <= n.second  && !s.count(n.first))
                    pq.push({n.second, n.first});
            }
        }
        // add the visited people to the result
        for(auto p : s) res.push_back(p);
        return res;
    }
};


// TODO: Solution using BFS,DFS and Union Find
