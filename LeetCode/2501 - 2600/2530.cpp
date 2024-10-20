// 2530. Maximal Score After Applying K Operations

// Solution 1 using Priority Queue
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long int res = 0;
        while(k--){
            double t = pq.top();
            pq.pop();
            res += t;
            pq.push(ceil(t/3));
        }
        return res;
    }
};