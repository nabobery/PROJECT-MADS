// 1346. Check If N and Its Double Exist

// Solution 1: Using Multiset
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        multiset<int> s(arr.begin(), arr.end());
        for(int it : s){
            if((it == 0 && s.count(it) > 1) || (it != 0 && s.count(it*2))) return true;
        }
        return false;
    }
};

// Solution 2: Using Unordered Set
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for(auto num : arr){
            if((num%2 == 0 && s.count(num/2)) || s.count(num*2)) return true;
            s.insert(num);
        }
        return false;
    }
};