// 2981. Find Longest Special Substring That Occurs Thrice I

// Solution 1: Using Brute Force
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    int maximumLength(string s) {
        map<string, int> mp;
        int n = s.size();
        for(int i = 0; i < n;i++){
            string temp;
            unordered_set<char> st;
            for(int j = i; j < n;j++){
                temp += s[j];
                st.insert(s[j]);
                if(st.size() == 1) mp[temp]++;
                else break;
            }
        }
        int res = -1;
        for(auto& it : mp){
            if(it.second >= 3){
                res = max(res, int(it.first.size()));
            }
        }
        return res;
    }
};

// Solution 2: Brute Force using map of pairs of char and int
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int> mp;
        int n = s.size();
        for(int i = 0; i < n;i++){
            string temp;
            unordered_set<char> st;
            for(int j = i; j < n;j++){
                temp += s[j];
                st.insert(s[j]);
                if(st.size() == 1) mp[{s[j], j-i+1}]++;
                else break;
            }
        }
        int res = -1;
        for(auto& it : mp){
            if(it.second >= 3){
                res = max(res, it.first.second);
            }
        }
        return res;
    }
};