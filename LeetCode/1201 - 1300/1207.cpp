// 1207. Unique Number of Occurrences

// Simple and Naive Solution using Hashmap and Set
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int num : arr) mp[num]++;
        unordered_set<int> s;
        for(auto it : mp) s.insert(it.second);
        return s.size() == mp.size();
    }
};

// Solution 2 without using Hashmap
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int freq[2001] = {0};
        for(int num : arr) freq[num+1000]++;
        unordered_set<int> s;
        for(int i=0;i<2001;i++) {
            if(freq[i] == 0) continue;
            if(s.find(freq[i]) != s.end()) return false;
            s.insert(freq[i]);
        }
        return true;
    }
};