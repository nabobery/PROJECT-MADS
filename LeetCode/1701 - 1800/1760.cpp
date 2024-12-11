// 1760. Minimum Limit of Balls in a Bag

// Solution 1 using Binary Search
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
class Solution {
public:
    // returns the minimum number of bags needed for the given maxBalls (Penalty)
    int bagspossible(vector<int>& nums, int maxBalls){
        int res = 0;
        for(int num: nums)
            if(num >= maxBalls) res += num/maxBalls + (num%maxBalls != 0);
            else res += 1;
        return res;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        // Binary Search through maximum size of a bag / Penalty 
        // bags is the total number of bags(target)
        int lo = 1, hi = 1e9, res = 1, bags = maxOperations + nums.size();
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(bagspossible(nums, mid) <= bags){
                hi = mid-1;
                res = mid;
            }
            else
                lo = mid+1;
        }
        return res;
    }
};
