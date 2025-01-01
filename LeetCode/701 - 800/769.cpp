// 769. Max Chunks To Make Sorted

// Solution 1: Greedy Approach using Unordered Set
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, n = arr.size();
        unordered_set<int> curr, chunk;
        for(int i = 0; i < n;i++){
            curr.insert(i);
            chunk.insert(arr[i]);
            if(curr == chunk){
                res++;
                curr.clear();
                chunk.clear();
            }
        }
        return res;
    }
};

// Solution 2: Greedy Approach using Two Pointers
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, n = arr.size(), max_val = 0;
        for(int i = 0; i < n;i++){
            max_val = max(max_val, arr[i]);
            if(max_val == i) res++;
        }
        return res;
    }
};