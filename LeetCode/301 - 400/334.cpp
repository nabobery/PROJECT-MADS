// 334. Increasing Triplet Subsequence

// greedy approach to ensure there're 3 numbers such that increasing triplet exists (It can aslo be thought of as find a LIS of length 3)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        int i = INT_MAX, j = INT_MAX;
        for(int num : nums){
            // the 1st num (if number less than 1st ,we replace and start over again)
            if(num <= i) i = num;
            // 2nd num greater than current 1st and if number less than 2nd ,we replace and start over again
            else if(num <= j) j = num;
            // if we find a number greater than 2nd ,we return true
            else return true;
        }
        return false;
    }
};

