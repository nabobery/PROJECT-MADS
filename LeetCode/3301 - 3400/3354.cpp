// 3354. Make Array Elements Equal to Zero

// Solution 1: Simple and Straightforward
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int res = 0, r = accumulate(nums.begin(), nums.end(), 0), l = 0;
        for(int& num: nums){
            if(num == 0){
                // check if left sum and right sum are equal or differ by 1
                // if equal, we can select both directions
                if(l == r) res += 2;
                // if differ by 1, we can select one direction
                else if(abs(l-r) == 1) res += 1;
            } 
            l += num;
            r -= num;
        }
        return res;
    }
};