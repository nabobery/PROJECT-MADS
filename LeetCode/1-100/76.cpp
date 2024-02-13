// 76. Minimum Window Substring

// Solution Naive and Simple using Two Pointers TLE
// Time Complexity: O(n^2logn)
// Space Complexity: O(n)
class Solution {
public:
    bool isSubset(map<char,int>& s, map<char,int>& t){
        for(auto& it : t)
            if(s[it.first] < it.second) return false;
        return true;
    }
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if(m < n) return "";
        string res = string('a', m+1);
        map<char,int> count_s, count_t;
        for(char ch : t) count_t[ch]++;
        int l,r;
        for(r = 0; r < m;r++){
            count_s[s[r]]++;
            if(isSubset(count_s, count_t)){
                res = s.substr(0,r+1);
                break;
            }
        }
        if(r < m) r++;
        for(int l = 0; l < m;l++){
            count_s[s[l]]--;
            while(!isSubset(count_s, count_t) && r < m){
                count_s[s[r]]++;
                r++;
            }
            cout<<l<<" "<<r<<"\n";
            if(isSubset(count_s, count_t)){
               if(r-l-1 < res.size()) res = s.substr(l+1, r-l-1);;
            }
        }
        if(res.size() > m) return "";
        return res;
    }
};

// Solution using Two Pointers and Hash Map
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    bool isSubset(unordered_map<char,int>& s, unordered_map<char,int>& t){
        for(auto& it : t)
            if(s[it.first] < it.second) return false;
        return true;
    }
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if(m < n) return "";
        unordered_map<char,int> count_s, count_t;
        for(char ch : t) count_t[ch]++;
        int l,r, ind = 0, sz = m+1;
        for(r = 0; r < m;r++){
            count_s[s[r]]++;
            if(isSubset(count_s, count_t)){
                sz = r+1;
                break;
            }
        }
        if(r < m) r++;
        for(int l = 0; l < m;l++){
            count_s[s[l]]--;
            while(!isSubset(count_s, count_t) && r < m){
                count_s[s[r]]++;
                r++;
            }
            if(isSubset(count_s, count_t)){
               if(r-l-1 < sz){
                   ind = l+1;
                   sz = r-l-1;
               }
            }
        }
        if(sz > m) return "";
        return s.substr(ind, sz);
    }
};

// Solution using Two Pointers and Hash Map
// Time Complexity: O(n+m)
// Space Complexity: O(n)
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if(m < n) return "";
        unordered_map<char,int> count_s, count_t;
        for(char ch : t) count_t[ch]++;
        int l = 0, r = 0, ind = 0, sz = m+1, cnt = 0;
        while(r < m){
            if(count_t.find(s[r]) != count_t.end()){
                count_s[s[r]]++;
                if(count_s[s[r]] == count_t[s[r]]) cnt++;
            }
            while(cnt == count_t.size() && l <= r){
                if(r-l+1 < sz){
                    ind = l;
                    sz = r-l+1;
                }
                if(count_t.find(s[l]) != count_t.end()){
                    count_s[s[l]]--;
                    if(count_s[s[l]] < count_t[s[l]]) cnt--;
                }
                l++;
            }
            r++;
        }
        if(sz > m) return "";
        return s.substr(ind, sz);
    }
};