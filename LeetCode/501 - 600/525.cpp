// 525. Contiguous Array
// using unordered_map O(n) time and O(n) space
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int count = 0, result = 0; // count is  to store the relative number of ones and zeros
        mp[0] = -1;
        // if count = 0, it implies we have equal number of zeroes and ones till now
        // if we encounter the same count twice it means that we have encountered equal number of zeroes and ones
        // basically count - equal number of zeroes + equal number of ones = count
        for(int i = 0; i < n;i++){
            count += (nums[i] == 1 ? 1 : -1);
            if(mp.find(count) != mp.end()){
                result = max(result, i - mp[count]);
            }
            else{
                mp[count] = i;
            }
        }
        return result;
    }
};

