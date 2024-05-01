// 1915. Number of Wonderful Substrings

// Naive TLE Solution by generating all substrings and checking if they are wonderful or not
// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
public:
    int cnt[10];
    bool isValid(){
        bool b = false;
        for(int c : cnt){
            if(b && c%2) return false;
            if(!b) b = c%2;
        }
        return true;
    }
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        long long res = 0;
        for(int l = 0; l < n;l++){
            memset(cnt, 0, sizeof(cnt));
            for(int r = l; r < n;r++){
                cnt[word[r] - 'a']++;
                if(isValid()) res++;
            }
        }
        return res;
    }
};

// Solution 1 using Bitmask and Prefix XOR and Hash Table
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int,int> mp;
        long long res = 0;
        int mask = (1 << 10) - 1;
        mp[mask] = 1;
        for(char ch : word){
            int k = ch - 'a';
            mask ^= (1 << k);
            mp[mask]++;
            for(int i = 0; i < 10;i++)
                if(mp.count(mask ^ (1 << i))) res += mp[mask ^ (1 << i)];
            res += mp[mask]-1;
        }  
        return res;
    }
};

// Solution 2 using Bitmask and Prefix XOR and Array
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> mp(1024);
        long long res = 0;
        int mask = 0;
        mp[0] = 1;
        for(char ch : word){
            int k = ch - 'a';
            mask ^= (1 << k);
            res += mp[mask];
            for(int i = 0; i < 10;i++)
                res += mp[mask ^ (1 << i)];
            mp[mask]++;
        }  
        return res;
    }
};