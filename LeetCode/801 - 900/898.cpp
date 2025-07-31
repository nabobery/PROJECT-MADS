// 898. Bitwise ORs of Subarrays

// Solution 1: By Maintaining the last or of each subarray ending in index i
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> s, curr;
        for(int i = 0; i < n;i++){
            unordered_set<int> temp;
            for(auto& it : curr) temp.insert(arr[i] | it);
            temp.insert(arr[i]);
            s.insert(temp.begin(), temp.end());
            curr = temp;
        }
        return s.size();
    }
};