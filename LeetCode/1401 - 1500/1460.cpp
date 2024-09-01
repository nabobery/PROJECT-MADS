// 1460. Make Two Arrays Equal by Reversing Subarrays

// As long as the two arrays have the same elements, they can be equal after some operations of reversing subarrays.

// Solution 1 using multiset
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        multiset<int> s1, s2;
        for(int num: target) s1.insert(num);
        for(int num: arr) s2.insert(num);
        return s1 == s2;
    }
};

// Solution 2 using map
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> m;
        for(int num: target) m[num]++;
        for(int num: arr) {
            if(m.find(num) == m.end()) return false;
            m[num]--;
            if(m[num] == 0) m.erase(num);
        }
        return m.empty();
    }
};

// Solution 3 using sorting
// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return target == arr;
    }
};