// 2200. Find All K-Distant Indices in an Array

// Solution 1: Simple and Straight Forward using boolean array
// This solution iterates through the array and marks indices that are k-distant from any occurrence
// Time Complexity: O(n*k)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> kDistant(n, false);
        for(int i = 0; i < n;i++){
            if(nums[i] == key){
                for(int j = max(0, i -k); j < min(n, i + k+1);j++) 
                    kDistant[j] = true;
            }
        }
        vector<int> res;
        for(int i = 0; i < n;i++)
            if(kDistant[i]) res.push_back(i);
        return res;
    }
};