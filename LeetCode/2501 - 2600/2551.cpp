// 2551. Put Marbles in Bags

// Solution 1: Using Heaps
// The Idea is to use two heaps, one max heap and one min heap, to find the maximum and minimum sums of weights that can be obtained by putting the marbles in bags.
// score(P)= weights[0]+weights[n−1]+ ∑ (weights[P[i]]+weights[P[i]+1]) (all the possible pairs of previous ending and current starting points)
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            long long res = 0;
            int n = weights.size(), cnt = 1;
            priority_queue<int> maxHeap;
            for(int i =1; i < n;i++) maxHeap.push(weights[i] + weights[i-1]);
            while(!maxHeap.empty() && cnt < k) {
                res += maxHeap.top();
                maxHeap.pop();
                cnt++;
            }
            priority_queue<int, vector<int>, greater<int>> minHeap;
            for(int i =1; i < n;i++) minHeap.push(weights[i] + weights[i-1]);
            while(!minHeap.empty() && cnt > 1){
                res -= minHeap.top();
                minHeap.pop();
                cnt--;
            }
            return res;
        }
};
    