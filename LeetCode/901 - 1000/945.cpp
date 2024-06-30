// 945. Minimum Increment to Make Array Unique

// Solution 1 Greedy Approach using Sorting
// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 1; i < n;i++){
            if(nums[i] <= nums[i-1]){
                res += abs(nums[i] - nums[i-1]) + 1;
                nums[i] = nums[i-1]+1;
            }
        }   
        return res;
    }
};

// Solution 2 Greedy Approach with Counting using Hashmap
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> count(100002, 0);
        for(int i = 0; i < n; i++)
            count[nums[i]]++;
        for(int i = 0; i <= 100000; i++){
            if(count[i] > 1){
                res += count[i] - 1;
                count[i+1] += count[i] - 1;
            }
        }
        res += ((count.back())*(count.back() - 1)) /2;
        return res;
    }
};