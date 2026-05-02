// 2615. Sum of Distances

// Solution 1: Prefix Sum and Suffix Sum
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n, 0);
        unordered_map<int, vector<int>> numToIndices;
        // Group the indices of the same number together
        for(int i = 0; i < n;i++) numToIndices[nums[i]].push_back(i);
        // For each group of indices, calculate the sum of distances using prefix sum and suffix sum
        for(auto& it: numToIndices){
            auto& indices = it.second;
            long long l = 0, r = accumulate(indices.begin(), indices.end(), 0L);
            int sz = indices.size();
            for(int i = 0; i < sz;i++){
                r -= indices[i];
                // The formula to calculate the sum of distances for the current index
                // left count * current index - left sum + right sum - right count * current index
                res[indices[i]] = (2*i -sz + 1) * (long long)indices[i] + r - l;
                l += indices[i];
            }
        }
        return res;
    }
};