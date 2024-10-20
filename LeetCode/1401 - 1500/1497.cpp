// 1497. Check If Array Pairs Are Divisible by k

// Solution 1 using Hash Map
// Time complexity: O(n)
// Space complexity: O(k)
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int num : arr) mp[(num%k+k)%k]++;
        for(auto it: mp){
            if(it.first != 0 && mp[it.first] != mp[k - it.first])
                return false;
        }
        return mp[0]%2 == 0;
    }
};

// Solution 2 using Array
// Time complexity: O(n)
// Space complexity: O(k)
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int cnt[k];
        memset(cnt, 0, sizeof(cnt));
        for(int num : arr) cnt[(num%k+k)%k]++;
        for(int i = 1; i < k; i++)
            if(cnt[i] != cnt[k - i])
                return false;
        return cnt[0]%2 == 0;
    }
};