// 857. Minimum Cost to Hire K Workers

// Solution 1 Greedy using sorting and priority queue

// Time complexity: O(nlogn + nlogk)
// Space complexity: O(n + k)

// The idea is to sort the workers by the ratio of wage to quality in ascending order as we want to minimize the cost.
// We iterate through all workers in sorted order and calculate the minimum cost.
// We can calculate the minimum cost for the current group of K workers by adding the quality of worker to sum and push it to priority queue and then multiplying it with the ratio of wage to quality of the current worker so that it satisfies the condition of minimum wage

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        vector<pair<double, int>> workers;
        // store the ratio of wage to quality and quality of each worker
        for (int i = 0; i < n; ++i) 
            //workers.push_back({(double)wage[i] / quality[i], quality[i]});
            workers.push_back({static_cast<double>(wage[i]) / quality[i], quality[i]});
        // sort workers by ratio of wage to quality in ascending order
        sort(workers.begin(), workers.end());
        double res = DBL_MAX;
        int sum = 0;
        // a priority queue to store the group of K smallest quality workers 
        priority_queue<int> pq;
        // iterate through all workers in sorted order and calculate the minimum cost
        for (int i = 0; i < n; ++i) {
            // add the quality of worker to sum and push it to priority queue
            sum += workers[i].second;
            pq.push(workers[i].second);
            // if the size of priority queue is greater than K, remove the worker with highest quality
            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }
            // if the size of priority queue is equal to K, calculate the minimum cost
            if (pq.size() == K)
                // the minimum cost for the current group is the sum of quality of K workers with highest ratio of wage to quality if the current worker is included
                res = min(res, sum * workers[i].first);
        }
        return res;
    }
};