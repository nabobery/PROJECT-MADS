// 2070. Most Beautiful Item for Each Query

// Solution 1 using Sorting and Priority Queue
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int q = queries.size(), k =0, n = items.size();
        vector<pair<int,int>> query_pairs(q);
        vector<int> res(q, 0);
        for(int i = 0; i < q;i++) query_pairs[i] = {queries[i], i};
        priority_queue<int> pq;
        sort(items.begin(), items.end());
        sort(query_pairs.begin(), query_pairs.end());
        for(int i = 0; i < q;i++){
            while(k < n && items[k][0] <= query_pairs[i].first){
                pq.push(items[k][1]);
                k++;
            }
            if(!pq.empty()) res[query_pairs[i].second] = pq.top();
        }
        return res;
    }
};