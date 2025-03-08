// 2379. Minimum Recolors to Get K Consecutive Black Blocks

// Solution 1 using Two Pointers
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n = blocks.size(), mx, curr = 0;
            for(int i = 0; i < k;i++) curr += (blocks[i] == 'B');
            mx = curr;
            for(int i = k; i < n;i++){
                curr += (blocks[i] == 'B');
                curr -= (blocks[i-k] == 'B');
                mx = max(curr, mx);
            }
            return (k - mx);
        }
};