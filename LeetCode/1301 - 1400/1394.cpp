// 1394. Find Lucky Integer in an Array

// Solution 1: Using a frequency map
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> cnt;
        for(int& num : arr) cnt[num]++;
        int res = -1;
        for(auto& it : cnt)
            if(it.first == it.second) res = it.first;
        return res;
    }
};

// Solution 2: Using a frequency array
// Time Complexity: O(n)
// Space Complexity: O(1) (since the range of numbers is limited)
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int cnt[501] = {0}; 
        for(int& num : arr) cnt[num]++;
        for(int i = 500; i >= 1; --i)
            if(cnt[i] == i) return i;
        return -1;
    }
};