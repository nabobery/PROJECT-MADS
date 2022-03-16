// 560. Subarray Sum Equals K

/* naive solution TLE
 class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;
        for(int i = 0; i < n;i++){
            int sum = 0;
            for(int j = i; j <  n;j++){
                sum += nums[j];
                if(sum == k){
                    result++;
                }
            }
        }
        return result;
    }
};
};
 */

// O(n) time and space solution using unordered map
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int result = 0,sum = 0;
        for(int num : nums){
            sum += num;
            if(mp.find(sum - k) != mp.end()){
                result += mp[sum - k];
            }
            mp[sum]++;
        }
        return result;
    }
};

