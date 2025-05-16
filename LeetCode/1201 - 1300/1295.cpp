// 1295. Find Numbers with Even Number of Digits

// Solution 1: Simple and Straight Forward Approach
// Time Complexity: O(n) where n is the number of elements in the array (o(n) *log10(num)) => O(n)
// Space Complexity: O(1) as we are using only a constant amount of space
class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int res = 0;
            for(int& num: nums){
                int curr = log10(num) + 1;
                res += (curr%2 == 0);
            }
            return res;
        }
};