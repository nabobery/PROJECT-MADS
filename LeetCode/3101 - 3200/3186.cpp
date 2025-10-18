// 3186. Maximum Total Damage With Spell Casting

// Solution 1: Using Map, Two Pointers and Dynamic Programming
// Time Complexity: O(nlogk)
// Space Complexity: O(n)
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        long long res = 0, mx = 0;
        map<int,int> damageCnt;
        for(auto& p: power) damageCnt[p]++;
        int n = damageCnt.size(), p = 0, p1 = n-1, p2 = n-1;
        vector<pair<int,long long>> spells(n);
        for(auto& it : damageCnt) spells[p++] = {it.first, it.first*1LL*it.second};
        while(p1 >= 0){
            while(p1 < p2 && spells[p2].first > spells[p1].first+2){
                mx = max(mx, spells[p2].second);
                p2--;
            }
            spells[p1].second += mx;
            res = max(res, spells[p1].second);
            p1--;
        }
        return res;
    }
};

// Solution 2: Using Sorting, Two Pointers and Dynamic Programming
// Time Complexity: O(n + klogk)
// Space Complexity: O(k) where k is the number of unique power values
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> damageCnt;
        for (int p : power)
            damageCnt[p]++;
        vector<pair<int, long long>> spells;
        spells.reserve(damageCnt.size());
        for (auto const& [dmg, count] : damageCnt) 
            spells.push_back({dmg, (long long)dmg * count});
        sort(spells.begin(), spells.end());
        long long res = 0,  mx = 0; 
        int n = spells.size(), p2 = n - 1;
        for (int p1 = n - 1; p1 >= 0; p1--) {
            while (p2 > p1 && spells[p2].first > spells[p1].first + 2) {
                mx = max(mx, spells[p2].second);
                p2--;
            }
            spells[p1].second += mx;
            res = max(res, spells[p1].second);
        }
        return res;
    }
};