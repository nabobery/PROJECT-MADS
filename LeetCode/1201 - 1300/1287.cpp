// 1287. Element Appearing More Than 25% In Sorted Array

// Solution 1 using map
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto num : arr) mp[num]++;
        for(auto it : mp){
            if(it.second > arr.size()/4) return it.first;
        }
        return -1;
    }
};

// Solution 2 by moving n/4 steps ahead
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int sz = arr.size()/4;
        for(int i=0; i< arr.size() - sz; i++){
            if(arr[i] == arr[i+sz]) return arr[i];
        }
        return -1;
    }
};


// Solution 3 by binary search
// Time complexity: O(logn)
// Space complexity: O(1)
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int sz = arr.size();
        vector<int> v = {arr[sz/4], arr[sz/2], arr[3*sz/4]};
        for(auto num : v){
            auto it = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
            auto it2 = upper_bound(arr.begin(), arr.end(), num) - arr.begin() - 1;
            if(it2 - it + 1 > sz/4) return num;
        }
        return -1;
    }
};