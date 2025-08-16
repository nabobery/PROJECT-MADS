// 31. Next Permutation

// Solution 1: Simple and Straight Forward (Narayana Panditha's algorithm)
// Time Complexity: O(n)
// Space Complexity O(1) (in place)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Doing it from the right because we want in Lexocagraphical Order
        int n = nums.size(), k = -1, l = n - 1;
        // Find the Pivot (where ai < ai+1) from the right
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                k = i;
                break;
            }
        }
        // Find the Successor (smallest element > pivot) from the right
        // Swap the Pivot and Sucessor
        if (k != -1) {
            for (int i = n - 1; i > k; i--) {
                if (nums[i] > nums[k]) {
                    l = i;
                    break;
                }
            }
            swap(nums[l], nums[k]);
        }
        // Reverse the Suffix (pivot to end) (because until the pviot they're in increasing order from right)
        int i = k + 1, j = n - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};
