// 3005. Count Elements With Maximum Frequency

// Solution 1 using Hash Map
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int mx = 0, res = 0;
        unordered_map<int,int> mp;
        for(int num: nums){
            mp[num]++;
            mx = max(mx, mp[num]);
        }
        for(auto it : mp)
            if(it.second == mx) res++;
        return res*mx;
    }
};

// Solution 2 using Sorting
// Time complexity: O(nlogn)
// Space complexity: O(logn)
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        sort(nums.begin(), nums.end());
        int mx = 0, res = 0, cnt = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]) cnt++;
            else cnt = 1;
            mx = max(mx, cnt);
        }
        cnt = 1;
        for(int i = 1; i < n; i++){
            if(cnt == mx) res++;
            if(nums[i] == nums[i-1]) cnt++;
            else cnt = 1;
        }
        if(cnt == mx) res++;
        return res*mx;
    }
};