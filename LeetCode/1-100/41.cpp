// 41. First Missing Positive

// Solution 1 Naive and Simple using Hashset
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for(int num : nums)
            if(num > 0) s.insert(num);
        for(int i=1; ;i++)
            if(!s.count(i)) return i;
        return 1;
    }
};

// Solution 2 Using Cyclic Sort
// Time Complexity: O(n)
// Space Complexity: O(1)

// The idea is to place each number in its correct position and place all the positive numbers in the range [1, n] at the beginning of the array and neglect the rest of the numbers
// After placing all the numbers in their correct position, we can iterate over the array to find the first number that is misplaced
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++)
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i])
                swap(nums[i], nums[nums[i]-1]);
        for(int i=0; i<n; i++)
            if(nums[i] != i+1) return i+1;
        return n+1;
    }
};