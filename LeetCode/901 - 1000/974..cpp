// 974. Subarray Sums Divisible by K

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mod(k,0);
        int result = 0,sum = 0;
        mod[0] = 1;
        for(int num : nums){
            sum += (num%k + k);
            sum %= k;
            result += mod[sum];
            mod[sum]++;
        }
        return result;
    }
};