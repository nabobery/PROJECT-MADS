// 2182. Construct String With Repeat Limit

// Naive Solution 1 using Priority Queue (Time Limit Exceeded)
// Time complexity: O(n^2logn)
// Space complexity: O(n)
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string res;
        priority_queue<char> pq(s.begin(), s.end());
        char prev = '#';
        int count = 0;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            if(prev == curr){
                count++;
                if(count > repeatLimit) continue;
                else res += curr;
            }
            else{
                if(count > repeatLimit)
                    for(int i = 0; i < count-repeatLimit;i++) pq.push(prev);
                count = 1;
                res += curr;
                prev = curr;
            }
        }
        return res;
    }
};

// Solution 2 using Map
// Time complexity: O(nlogk)
// Space complexity: O(n)
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string res;
        map<char,int> mp;
        for(char& ch: s) mp[ch]++;
        while(mp.size() > 1){
            auto it = mp.rbegin();
            if(it->second <= repeatLimit){
                res += string(it->second, it->first);
                mp.erase(it->first);
            }
            else{
                res += string(repeatLimit, it->first);
                mp[it->first] -= repeatLimit;
                auto prev = it;
                prev++;
                res += prev->first;
                prev->second--;
                if(prev->second == 0) mp.erase(prev->first);
            }
        }
        auto it = mp.begin();
        char prev = !res.empty() ? res.back() : '#';
        if(prev != it->first) res += string(min(it->second, repeatLimit), it->first);
        return res;
    }
};

// Solution 3 using Vector 
// Time complexity: O(nk)
// Space complexity: O(n)
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string res;
        vector<int> mp(26, 0);
        for(char& ch: s) mp[ch-'a']++;
        int curr = 25;
        while(curr >= 0){
           if(mp[curr] == 0){
            curr--;
            continue;
           }
           int use = min(mp[curr], repeatLimit);
           res.append(use, curr+'a');
           mp[curr] -= use;
           if(mp[curr] > 0){
            int next = curr-1;
            while(next >= 0 && mp[next] == 0) next--;
            if (next < 0) break;
            res.push_back(next+'a');
            mp[next]--;
           }
        }
        return res;
    }
};  

// Efficient Solution using Priority Queue and Hashmap
// Time complexity: O(nlogk)
// Space complexity: O(n)
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string res;
        unordered_map<char, int> mp;
        for(char& ch: s) mp[ch]++;
        priority_queue<char> pq;
        for(auto it: mp) pq.push(it.first);
        while(!pq.empty()){
            char ch = pq.top();
            pq.pop();
            int use = min(mp[ch], repeatLimit);
            res.append(use, ch);
            mp[ch] -= use;
            if(mp[ch] > 0 && !pq.empty()) {
                char next = pq.top();
                pq.pop();
                res.push_back(next);
                mp[next]--;
                if (mp[next] > 0) pq.push(next);
                pq.push(ch);
            }
        }
        return res;
    }
};