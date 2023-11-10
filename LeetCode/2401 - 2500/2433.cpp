// 2433. Find The Original Array of Prefix Xor

// Solution 1 Using Xor property
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res(pref.size());
        res[0] = pref[0];
        for(int i = 1; i < pref.size();i++){
            res[i] = pref[i] ^ pref[i-1];
        }
        return res;
    }
};

// Solution 2 Using Xor property in Space Optimized way
// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        for(int i = pref.size()-1; i > 0;i--){
            pref[i] = pref[i] ^ pref[i-1];
        }
        return pref;
    }
};