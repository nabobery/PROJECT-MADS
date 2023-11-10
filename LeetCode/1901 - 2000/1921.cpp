// 1921. Eliminate Maximum Number of Monsters

// Solution 1 based on Greedy Approach (Sorting)
// Time Complexity => O(nlogn)
// Space Complexity => O(n)
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> timereq(n, 0);
        for(int i = 0;i < n;i++){
            timereq[i] = dist[i]/speed[i] + (dist[i]%speed[i] != 0);
        }
        sort(timereq.begin(), timereq.end());
        int p = 0;
        for(int i = 0; i < n;i++){
            if(p < timereq[i]) p++;
            else return i;
        }
        return n;
    }
};

// Solution 2 based on Greed Approach without using additional memory
// Time Complexity => O(nlogn)
// Space Complexity => O(1)

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        for(int i = 0;i < n;i++){
            dist[i] = dist[i]/speed[i] + (dist[i]%speed[i] != 0);
        }
        sort(dist.begin(), dist.end());
        int p = 0;
        for(int i = 0; i < n;i++){
            if(p < dist[i]) p++;
            else return i;
        }
        return n;
    }
};

// Solution 3 based on Priority Queue
// Time Complexity => O(nlogn)
// Space Complexity => O(n)
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        priority_queue<double, vector<double>, greater<double>> pq;
        for(int i = 0;i < n;i++){
            pq.push((double)dist[i]/speed[i]);
        }
        int p = 0;
        while(!pq.empty()){
            if(p < pq.top()){
                p++;
                pq.pop();
            }
            else return n - pq.size();
        }
        return n;
    }
};