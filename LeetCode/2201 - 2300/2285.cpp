// 2285. Maximum Total Importance of Roads

// Solution 1 using Priority Queue
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        priority_queue<int> pq;
        for(auto road : roads){
            degree[road[0]]++;
            degree[road[1]]++;
        }
        long long res = 0;
        for(int d : degree) pq.push(d);
        while(!pq.empty()){
            res += pq.top()*pq.size();
            pq.pop();
        }
        return res;
    }
};


// Solution 2 using Sorting
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        for(auto road : roads){
            degree[road[0]]++;
            degree[road[1]]++;
        }
        sort(degree.begin(), degree.end());
        long long res = 0;
        for(int i = 0; i < n; i++) res += (long long)degree[i]*(i+1);
        return res;
    }
};