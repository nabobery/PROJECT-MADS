// 3375. Minimum Operations to Make Array Values Equal to K

// Solution 1 using Map
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            map<int,int> mp;
            int res = 0;
            for(int& num : nums) mp[num]++;
            if(mp.begin()->first < k) return -1;
            return mp.size() - mp.count(k);
        }
};

// Solution 2 using Boolean Array
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
    public:
        bool cnt[100];
        int minOperations(vector<int>& nums, int k) {
            memset(cnt, 0, sizeof(cnt));
            int res = 0, mi = 101;
            for(int& num : nums){
                mi = min(num, mi);
                if(mi < k) return -1;
                cnt[num-1] = true;
            }
            for(auto& b : cnt) if(b) res++;
            return res - (cnt[k-1] == true);
        }
};