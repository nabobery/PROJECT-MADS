// 2762. Continuous Subarrays

// Solution 1: Using Sliding Window and Map
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int,int> mp;
        int l = 0;
        long long res = 0;
        for(int r = 0; r < nums.size();r++){
            mp[nums[r]]++;
            auto it = mp.begin();
            auto it2 = mp.rbegin();
            if(abs(it->first - it2->first) > 2){
                while(abs(it->first - it2->first) > 2){
                    mp[nums[l]]--;
                    if(mp[nums[l]] == 0) mp.erase(nums[l]);
                    l++;
                    it = mp.begin();
                    it2 = mp.rbegin();
                }
            } 
            res += (r-l+1);
        }
        return res;
    }
};
