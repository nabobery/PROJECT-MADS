// 3660. Jump Game IX

// Solution 1: Prefix and Suffix Arrays
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        // prefixMax[i] stores the maximum value from nums[0] to nums[i]
        vector<int> res(n), prefixMax(n);
        prefixMax[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        // suffixMin[i] stores the minimum value from nums[i] to nums[n - 1]
        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) 
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        // if subarry A and subarray B are two components, then max(A) <= min(B)
        // we can find the components by comparing prefixMax and suffixMin
        int componentStart = 0;
        for (int i = 0; i < n; i++) {
            // if i is the last index or prefixMax[i] <= suffixMin[i + 1], then we can split the array into two components
            if (i == n - 1 || prefixMax[i] <= suffixMin[i + 1]) {
                // fill the result for the current component with the maximum value of the component
                int maxVal = prefixMax[i];
                // the current component is from componentStart to i
                for (int j = componentStart; j <= i; j++) {
                    res[j] = maxVal;
                }
                // update the start index for the next component
                componentStart = i + 1;
            }
        }
        // return the result array
        return res;
    }
};