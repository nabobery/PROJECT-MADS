// 3318. Find X-Sum of All K-Long Subarrays I

// Solution 1: Using Priority Queue and Sliding Window
// Time Complexity: O(k * 50 log 50) -> O(k)
// Space Complexity: O(k)
class Solution {
public:
    int getSum(vector<int>& cnt, int x){
        int res = 0;
        priority_queue<pair<int,int>> pq;
        for(int i = 1; i < cnt.size();i++)
            if(cnt[i]) pq.push({cnt[i], i});
        while(!pq.empty() && x){
            auto curr = pq.top();
            pq.pop();
            res += curr.first*curr.second;
            x--;
        }
        return res;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> res(n-k+1, 0), cnt(51, 0);
        for(int i = 0; i < k;i++) cnt[nums[i]]++;
        res[0] = getSum(cnt, x);
        for(int i = k; i < n;i++){
            cnt[nums[i]]++;
            cnt[nums[i-k]]--;
            res[i-k+1] = getSum(cnt, x);
        }
        return res;
    }
};