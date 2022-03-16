// 1094. Car Pooling
// we add 2 pairs (start, passengers) and (end, -passengers) and add and check if the capacity is filled or not
// time : O(nlogn) and space : O(n) where n is number of trips
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector <pair<int,int>> v;
        for(auto t : trips){
            v.push_back({t[1],t[0]});
            v.push_back({t[2], -t[0]});
        }
        sort(v.begin(),v.end());
        int currLoad = 0;
        for(auto itr : v){
            currLoad += itr.second;
            if(currLoad > capacity) return false;
        }
        return true;
    }
};

// time : O(n) and space O(m) ( n is number of trips and m is number of stops which is 1000 here)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int stops[1001] = {};
        for (auto t : trips) stops[t[1]] += t[0], stops[t[2]] -= t[0];
        for (auto i = 0; capacity >= 0 && i < 1001; ++i) capacity -= stops[i];
        return capacity >= 0;
    }
};


