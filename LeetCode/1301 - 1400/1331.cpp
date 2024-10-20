// 1331. Rank Transform of an Array

// Solution 1 using Unordered Map and Set
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s(arr.begin(), arr.end());
        unordered_map<int,int> mp;
        int rank = 1;
        for(auto it : s) mp[it] = rank++;
        for(int& num : arr) num = mp[num]; 
        return arr;
    }
};

// Solution 2 using Sorting and Unordered Map
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int, int> rankMap;
        int rank = 1;
        for (int num : sortedArr) 
            if (!rankMap.count(num)) 
                rankMap[num] = rank++;
        for (int& num : arr) 
            num = rankMap[num];
        return arr;
    }
};

// Solution 3 using Sorting and vector
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        vector<int> rankMap;
        int rank = 1;
        for (int num : sortedArr) 
            if (rankMap.empty() || rankMap.back() != num) 
                rankMap.push_back(num);
        for (int& num : arr) 
            num = lower_bound(rankMap.begin(), rankMap.end(), num) - rankMap.begin() + 1;
        return arr;
    }
};