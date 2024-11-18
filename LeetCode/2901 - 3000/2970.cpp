// 2970. Count the Number of Incremovable Subarrays I

// Solution 1: Simple and Straightforward
// Time complexity: O(n^3)
// Space complexity: O(n)
class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for(int i = 0; i < n;i++){
            for(int j = i; j < n;j++){
                vector<int> temp;
                for(int k = 0; k < i;k++) temp.push_back(nums[k]);
                for(int k = j+1; k < n;k++) temp.push_back(nums[k]);
                bool b = true;
                for(int k = 1; k < temp.size();k++){
                    if(temp[k] <= temp[k-1]){
                        b = false;
                        break;
                    }
                }
                if(b) res++;
            }
        }
        return res;
    }
};

// Solution 2: Sliding Window + Prefix Sum
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_inc(n, 1), right_inc(n, 1);
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                left_inc[i] = left_inc[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                right_inc[i] = right_inc[i + 1] + 1;
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                bool is_valid = true;
                // check if the subarray is incremovable
                if (i > 0 && j < n - 1 && nums[i - 1] >= nums[j + 1]) {
                    is_valid = false;
                }
                // prefix is sorted
                if (i > 0 && left_inc[i - 1] != i) {
                    is_valid = false;
                }
                // suffix is sorted
                if (j < n - 1 && right_inc[j + 1] != (n - j - 1)) {
                    is_valid = false;
                }
                if (is_valid) {
                    res++;
                }
            }
        }
        return res;
    }
};