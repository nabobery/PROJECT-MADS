// 268. Missing Number
// My naive O(n) time and O(1) space solution
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        n = n*(n+1)/2;
        n -= sum;
        return n;
    }
};
