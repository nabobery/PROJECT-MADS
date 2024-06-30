// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

// Naive Solution by checking all the subarrays and finding the maximum length
// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = 1, n = nums.size(), mi, mx;
        for(int l = 0; l < n-1;l++){
            mi = nums[l], mx = nums[l];
            for(int r = l+1; r < n;r++){
                mx = max(mx, nums[r]), mi = min(mi, nums[r]);
                if(mx - mi > limit) break;
                res = max(res, r-l+1);
            }
        }
        return res;
    }
};

// Solution 2 using multiset (Optimised Solution 1)
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = 1, n = nums.size(), l = 0;
        multiset<int> s;
        for(int r = 0; r < n;r++){
            s.insert(nums[r]);
            if(*s.rbegin() - *s.begin() > limit){
                while(*s.rbegin() - *s.begin() > limit)
                    s.erase(s.find(nums[l++]));
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};

// Solution 3 using deque (Optimised Solution 2)
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = 1, n = nums.size(), l = 0;
        deque<int> mx, mi;
        for(int r = 0; r < n;r++){
            while(!mx.empty() && mx.back() < nums[r]) mx.pop_back();
            while(!mi.empty() && mi.back() > nums[r]) mi.pop_back();
            mx.push_back(nums[r]), mi.push_back(nums[r]);
            if(mx.front() - mi.front() > limit){
                if(mx.front() == nums[l]) mx.pop_front();
                if(mi.front() == nums[l]) mi.pop_front();
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};