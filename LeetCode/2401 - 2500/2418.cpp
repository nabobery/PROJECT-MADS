// 2418. Sort the People

// Solution 1 using map
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size(), p = 0;
        vector<string> res(n);
        map<int, string> mp;
        for(int i = 0; i < n;i++) mp[heights[i]] = names[i];
        for(auto it = mp.rbegin(); it != mp.rend(); it++)
            res[p++] = it->second;
        return res;
    }
};

// Solution 2 using custom comparator
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> people;
        for(int i = 0; i < n; i++) people.push_back({heights[i], names[i]});
        sort(people.begin(), people.end(), [](pair<int, string>& a, pair<int, string>& b) {
            return a.first > b.first;
        });
        vector<string> res;
        for(auto& p : people) res.push_back(p.second);
        return res;
    }
};