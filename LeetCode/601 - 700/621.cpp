// 621. Task Scheduler

// Solution 1 using Math and Greedy
// Time complexity: O(n)
// Space complexity: O(1)
// Situation 1: If there're no idle time, the answer is the length of the tasks
// Situation 2: If there're idle time, the answer is (mx-1)*(n+1) + count where mx is the maximum frequency of a task and count is the number of tasks that have the same frequency as mx
class Solution {
public:
    int cnt[26];
    int leastInterval(vector<char>& tasks, int n) {
        memset(cnt, 0, sizeof(cnt));
        int mx = 0, count = 0;
        for(char t : tasks){
            cnt[t - 'A']++;
            mx = max(cnt[t-'A'], mx);
        }
        for(int c : cnt) if(c == mx) count++;
        return max((int)tasks.size(), (mx-1)*(n+1) + count);
    }
};


// Solution 2 using Priority Queue
// Time complexity: O(nlogn)
// Space complexity: O(n)
// We can use a priority queue to store the tasks and their frequency. We can then pop the tasks from the queue and add them to the result. We can then add the tasks to the queue again if their frequency is not 0. We can then add the idle time to the result if the queue is empty and the number of tasks is not 0.
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for(char t : tasks) cnt[t - 'A']++;
        priority_queue<int> pq;
        for(int c : cnt) if(c) pq.push(c);
        int res = 0;
        while(!pq.empty()){
            vector<int> tmp;
            for(int i = 0; i <= n; i++){
                if(!pq.empty()){
                    int c = pq.top(); pq.pop();
                    if(c > 1) tmp.push_back(c-1);
                }
                res++;
                if(pq.empty() && tmp.empty()) break;
            }
            for(int t : tmp) pq.push(t);
        }
        return res;
    }
};