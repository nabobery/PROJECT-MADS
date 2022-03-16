// 334. Increasing Triplet Subsequence
// greedy approach to ensure there're 3 numbers such that increasing triplet exists
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        int i = INT_MAX, j = INT_MAX;
        for(int num : nums){
            // the 1st num (if number less than 1st ,we replace and start over again)
            if(num <= i) i = num;
            // 2nd num greater than 1st
            else if(num <= j) j = num;
            // found 3rd num then return true;
            else return true;
        }
        return false;
    }
};

