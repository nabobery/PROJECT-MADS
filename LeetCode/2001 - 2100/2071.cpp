// 2071. Maximum Number of Tasks You Can Assign

// Solution 1 Using Sorting, Binary Search and Greedy
// Time Complexity: O(n log n) where n is the number of tasks
// Space Complexity: O(n) where n is the number of tasks
class Solution {
public:
    // Function to check if it is possible to assign mid number of tasks
    // to workers with the given number of pills and strength
    // Assign the weakest mid tasks to the strongest mid workers
    bool check(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength){
        int n = tasks.size(), m = workers.size();
        // insert the strongest mid workers into a multiset
        multiset<int> workersSet;
        for(int i = m - mid; i < m;i++) workersSet.insert(workers[i]);
        // iterate through the weakest mid tasks
        for(int i = mid-1; i >= 0;i--){
            // if the strongest worker can do the task, assign it to him
            auto it = prev(workersSet.end());
            if(tasks[i] <= *it) workersSet.erase(it);
            // if the strongest worker cannot do the task, check if we can use a pill to assign the task
            else{
                // if there are no pills left, return false
                if(!pills) return false;
                // find the weakest worker that can do the task with the help of a pill
                auto it = workersSet.lower_bound(tasks[i] - strength);
                // if there is no such worker, return false
                if(it == workersSet.end()) return false;
                // if there is such a worker, assign the task to him and use a pill
                // erase the worker from the multiset
                pills--;
                workersSet.erase(it);
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        // the maximum result could be the minimum of tasks and workers
        int l = 1, r = min(tasks.size(), workers.size()), res = 0;
        // Sort tasks and workers in ascending order
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        // Binary search to find the maximum number of tasks that can be assigned to workers 
        while(l <= r){
            int mid = (l+r)/2;
            if(check(mid, tasks, workers, pills, strength)){
                res = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return res;
    }
}; 
