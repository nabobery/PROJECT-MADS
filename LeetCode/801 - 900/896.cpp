// 896. Monotonic Array

// Solution 1 using sort
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        if(nums == temp) return true;
        reverse(temp.begin(), temp.end());
        if(nums == temp) return true;
        return false;
    }
};

// Solution 2 using 2 traversals
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        bool b = true;
        for(int i = 1; i < n;i++){
            if(nums[i] >= nums[i-1]) continue;
            else{
                b = false;
                break;
            }
        }
        if(b) return b;
        b = true;
        for(int i = n-1; i > 0;i--){
            if(nums[i] <= nums[i-1]) continue;
            else{
                b = false;
                break;
            }
        }
        return b;
    }
};
