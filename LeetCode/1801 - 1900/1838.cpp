// 1838. Frequency of the Most Frequent Element

// Solution 1 - Bad Bruteforce by checking all the possible frequencies
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    map<int,int> mp;
    int maxPossible(int i, int k){
        int res = 0;
        auto it = mp.lower_bound(i);
        while(it != mp.begin() && k > 0){
            long long temp = (i-it->first);
            temp *= it->second;
            if(temp <= k){
                res += it->second;
                k -= temp;
            }
            else{
                res += (k/(i - it->first));
                k = 0;
            }
            it--;
        }
        if(k > 0){
            long long temp = (i-mp.begin()->first);
            temp *= mp.begin()->second;
            if(temp <= k)
                res += mp.begin()->second;
            else
                res += (k/(i - it->first));
        }
        return res;
    }
    int maxFrequency(vector<int>& nums, int k) {
        for(auto i : nums) mp[i]++;
        int res = 1;
        for(auto it : mp){
            res = max(res, maxPossible(it.first, k));
        }
        return res;
    }
};

// Solution 2 - Sliding Window Approach (Sort + Two Pointers)
// Time Complexity: O(nlogn)
// Space Complexity: O(logn)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 1, n = nums.size();
        long long sum = 0;
        for(int i = 0, j = 0; i < n; i++){
            sum += nums[i];
            while((long long)nums[i] * (i - j + 1) > sum + k){
                sum -= nums[j];
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};

// A more optimized Sliding Window Approach (Sort + Two Pointers)
// Time Complexity: O(nlogn)
// Space Complexity: O(logn)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int j = 0;
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if((long long)nums[i] * (i - j + 1) > sum + k){
                sum -= nums[j];
                j++;
            }
        }
        return nums.size() - j;
    }
};


// Solution 3 - Binary Search Approach
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    int helper(int i, int k, vector<int>& nums, vector<long>& prefix){
        int l = 0, r = i, res = i;
        while(l <= r){
            int mid = (l + r) / 2;
            if((long long)nums[i] * (i - mid + 1) - (prefix[i] - prefix[mid] + nums[mid]) <= k){
                r = mid-1;
                res = mid;
            }   
            else
                l = mid + 1;
        }
        return i - res + 1;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] + nums[i];
        int res = 1;
        for(int i = 1; i < n; i++)
            res = max(res, helper(i, k, nums, prefix));
        return res;
    }
};
