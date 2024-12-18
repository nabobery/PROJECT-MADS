// 2558. Take Gifts From the Richest Pile

// Solution 1 using Priority Queue
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long res = 0;
        priority_queue<int> pq(gifts.begin(), gifts.end());
        for(int i = 0; i < k;i++){
            int top = pq.top();
            pq.pop();
            pq.push(sqrt(top));
        }
        while(!pq.empty()){
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};
