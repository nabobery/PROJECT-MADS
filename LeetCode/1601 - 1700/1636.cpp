// 1636. Sort Array by Increasing Frequency

// Solution 1 using map and set
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        map<int, set<int, std::greater<int>>> cnt;
        vector<int> res;
        for(int num : nums) mp[num]++;
        for(auto it : mp)
            cnt[it.second].insert(it.first);
        for(auto it : cnt)
            for(auto k : it.second)
                for(int i = 0; i < it.first;i++) res.push_back(k);
        return res;
    }
};

// Solution 2 using map and custom comparator
// Time complexity: O(nlogn)
// Space complexity: O(n)
static unordered_map<int,int> mp;
class Solution {
public:
    static bool compare(int a, int b){
        if(mp[a] != mp[b]) return mp[a] < mp[b];
        return a > b;
    }
    vector<int> frequencySort(vector<int>& nums) {
        mp.clear();
        for(int num : nums) mp[num]++;
        sort(nums.begin(), nums.end(), compare);
        return nums;
    }
};

