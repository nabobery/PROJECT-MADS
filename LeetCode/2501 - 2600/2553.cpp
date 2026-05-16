// 2553. Separate the Digits in an Array

// Solution 1: Simulation by extracting digits and storing them in a temporary array, then reversing the order to maintain the original sequence of digits
// Time Complexity: O(n * log(m)), where n is the size of nums and m is the maximum number in nums
// Space Complexity: O(n * log(m)), for the result array
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (int num : nums) {
            vector<int> temp;
            while (num) {
                temp.push_back(num % 10);
                num /= 10;
            }
            for (int i = temp.size() - 1; i >= 0; i--)
                res.push_back(temp[i]);
        }
        return res;
    }
};

// Solution 2: Similar to Solution 1 but using a fixed-size array to store digits, which can be more efficient in terms of memory allocation
// Time Complexity: O(n * log(m)), where n is the size of nums and m
// Space Complexity: O(n * log(m)), for the result array
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        res.reserve(nums.size() * 5);

        for (int num : nums) {
            int digits[10];
            int idx = 0;

            while (num > 0) {
                digits[idx++] = num % 10;
                num /= 10;
            }

            while (idx > 0) {
                res.push_back(digits[--idx]);
            }
        }
        return res;
    }
};