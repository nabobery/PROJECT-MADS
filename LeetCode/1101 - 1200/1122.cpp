// 1122. Relative Sort Array

// Solution 1 - Using map
// Time complexity: O(nlogn)
// Space complexity: O(n)

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        map<int,int> mp;
        for(int num : arr1) mp[num]++;
        for(int num : arr2){
            if(mp[num]){
                while(mp[num]--)
                    res.push_back(num);
                mp.erase(num);
            }
        }
        for(auto it : mp){
            int c = it.second;
            while(c--) res.push_back(it.first);
        }
        return res;
    }
};

// Solution 2 - Using Custom Sort Function
// Time complexity: O(nlogn)
// Space complexity: O(n)

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(int i = 0; i < arr2.size(); i++) mp[arr2[i]] = i;
        sort(arr1.begin(), arr1.end(), [&](int a, int b){
            if(mp.count(a) && mp.count(b)) return mp[a] < mp[b];
            else if(mp.count(a) || mp.count(b)) return bool(mp.count(a));
            return a < b;
        });
        return arr1;
    }
};
