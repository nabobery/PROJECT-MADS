// 2225. Find Players With Zero or One Losses

// Solution 1 using Map of pairs
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res(2);
        map<int, pair<int,int>> mp;
        for(auto& it : matches){
            if(!mp.count(it[0])) mp[it[0]] = {0,0};
            if(!mp.count(it[1])) mp[it[1]] = {0,0};
            mp[it[0]] = {mp[it[0]].first+1, mp[it[0]].second+1};
            mp[it[1]].second += 1;
        }
        for(auto it : mp){
            int lost = it.second.second-it.second.first;
            if(lost <= 1) res[lost].push_back(it.first);
        }
        return res;
    }
};

// Solution 2 using Map 
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res(2);
        map<int, int> mp;
        for(auto& it : matches){
            if(!mp.count(it[0])) mp[it[0]] = 0;
            if(!mp.count(it[1])) mp[it[1]] = 0;
            mp[it[1]] += 1;
        }
        for(auto it : mp)
            if(it.second <= 1) res[it.second].push_back(it.first);
        return res;
    }
};