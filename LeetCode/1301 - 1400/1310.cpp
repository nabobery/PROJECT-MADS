// 1310. XOR Queries of a Subarray

// Solution 1 by maintaining prefix XOR array
// Time complexity: O(n + q)
// Space complexity: O(n)
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), m = queries.size();
        vector<int> prefix_xor(n+1, 0), res(m);
        for(int i = 0; i < n;i++) prefix_xor[i+1] ^= (prefix_xor[i] ^ arr[i]);
        for(int i = 0; i < m;i++) res[i] = (prefix_xor[queries[i][1]+1] ^ prefix_xor[queries[i][0]]);
        return res;
    }
};

