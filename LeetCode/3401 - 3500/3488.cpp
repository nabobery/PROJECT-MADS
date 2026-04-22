// 3488. Closest Equal Element Queries


// Solution 1: Hash Map + Binary Search
// Time Complexity: O(n + qlogn)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int q = queries.size(), n = nums.size();
        vector<int> res(q);
        // numToIndices[num] = [i1, i2, ...] where nums[i1] = nums[i2] = num
        unordered_map<int,vector<int>> numToIndices;
        for(int i = 0; i < n;i++) numToIndices[nums[i]].push_back(i);
        // For each query, find the closest index with the same value as nums[queries[i]]
        for(int i = 0; i < q;i++){
            auto& indices = numToIndices[nums[queries[i]]];
            int sz = indices.size();
            // If there is only one index, then there is no other index with the same value, so the answer is -1
            if(sz == 1) res[i] = -1;
            else{
                // Find the closest index to queries[i] in indices using binary search
                auto it = lower_bound(indices.begin(), indices.end(), queries[i]);
                int ind = it - indices.begin(), l = (ind - 1 + sz)%sz, r = (ind+1)%sz;
                // The closest index is either indices[l] or indices[r]
                int left = indices[l], right = indices[r];
                auto dist = [&](int j) {
                    return min(abs(j - queries[i]), n - abs(j - queries[i]));
                };
                // The answer is the minimum circular distance to either left or right
                res[i] = min(dist(left), dist(right));
            }
        }
        return res;
    }
};