// 136. Single Number
// xor of a and a is 0 and 0 ^ b = b. therefore we can find the number by taking xor of all elements
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];
        for(int i = 1; i < n;i++){
            result ^= nums[i];
        }
        return result;
    }
};

