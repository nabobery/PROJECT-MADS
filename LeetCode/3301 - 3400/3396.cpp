// 3396. Minimum Number of Operations to Make Elements in Array Distinct

// Solution 1: Using Unordered Map 
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            unordered_map<int,int> cnt;
            for(int& num: nums) cnt[num]++;
            int res = 0, j = 0, n = nums.size();
            while(j < n && n-j != cnt.size()){
                for(int i = j; i < n && i < j + 3;i++){
                    cnt[nums[i]]--;
                    if(cnt[nums[i]] == 0) cnt.erase(nums[i]);
                }
                j += 3;
                res++;
            }
            return res;
        }
};