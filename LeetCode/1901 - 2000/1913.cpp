// 1913. Maximum Product Difference Between Two Pairs

// Solution 1 Naive and Simple based on sorting
// Time Complexity = O(NlogN)
// Space Complexity = O(1)
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return (nums[nums.size()-1]*nums[nums.size()-2] - nums[0]*nums[1]);
    }
};

// Solution findinng max and second max and min and second min
// Time Complexity = O(N)
// Space Complexity = O(1)
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > max1){
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] > max2){
                max2 = nums[i];
            }
            if(nums[i] < min1){
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i] < min2){
                min2 = nums[i];
            }
        }
        return (max1*max2 - min1*min2);
    }
};