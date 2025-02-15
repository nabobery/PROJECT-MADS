// 3066. Minimum Operations to Exceed Threshold Value II

// Solution 1 using Priority Queue
// Time Complexity: O(NlogN)
// Space Complexity: O(N)
class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int res = 0;
            priority_queue<long, std::vector<long>, std::greater<long>> pq(
                nums.begin(), nums.end());
            while (pq.size() >= 2) {
                long mi1 = pq.top();
                if (mi1 >= k)
                    break;
                pq.pop();
                long mi2 = pq.top();
                pq.pop();
                pq.push(min(mi1, mi2) * 2 + max(mi1, mi2));
                res++;
            }
            return res;
        }
};