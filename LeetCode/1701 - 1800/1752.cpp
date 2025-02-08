// 1752. Check if Array Is Sorted and Rotated

// Solution 1: Straightforward by comparing the sorted array with the given array
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> sortedNums(nums.begin(), nums.end());
        sort(sortedNums.begin(), sortedNums.end());
        int n = nums.size();
        for(int i = 0; i < n;i++){
            bool b = true;
            for(int j = 0; j < n;j++){
                if(sortedNums[j] != nums[(i+j)%n]){
                    b = false;
                    break;
                }
            }
            if(b) return true;
        }
        return false;
    }
};

// Solution 2: Find the number of rotations
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int rotations = 0;
        for(int i = 0; i < n;i++){
            if(nums[i] > nums[(i+1)%n]){
                rotations++;
            }
        }
        return rotations <= 1;
    }
};