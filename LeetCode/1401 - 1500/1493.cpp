// 1493. Longest Subarray of 1's After Deleting One Element

// Solution 1: Simple and StraightForward by maintaing the map of 1's subarray
// Time Complexity: O(n) where n is the number of elements in the array
// Space Complexity: O(n) since we are using a map to store the indices of 1's subarray
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), res;
        vector<pair<int,int>> cnt;
        for(int i = 0; i < n;i++){
            if(nums[i]){
                int j = i;
                while(j < n && nums[j]) j++;
                cnt.push_back({i, j-i});
                i=j-1;
            }
        }
        if(cnt.empty()) return 0;
        if(cnt.size() == 1 && cnt[0].second == n) return n-1;
        res = cnt[0].second;
        for(int i = 1; i < cnt.size();i++){
            res = max(res, cnt[i].second);
            if((cnt[i-1].first + cnt[i-1].second+1) == cnt[i].first){
                res = max(res, cnt[i-1].second + cnt[i].second);
            }
        }
        return res;
    }
};

// Solution 2: Using Sliding Window
// Time Complexity: O(n) where n is the number of elements in the array
// Space Complexity: O(1) since we are using only a constant amount of extra space
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, zeroCount = 0, maxLength = 0;
        while (right < n) {
            if (nums[right] == 0) zeroCount++;
            while (zeroCount > 1) {
                if (nums[left] == 0) zeroCount--;
                left++;
            }
            maxLength = max(maxLength, right - left);
            right++;
        }
        return maxLength;
    }
};