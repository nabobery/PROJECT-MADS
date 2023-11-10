// 1759. Count Number of Homogenous Substrings

// Solution 1 using Hashmap
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int mod = 1e9+7;
    int countHomogenous(string s) {
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i < s.size();i++)
            mp[s[i]].push_back(i);
        long long res = 0;
        for(auto it : mp){
            int count = 1;
            for(int i = 1; i < it.second.size();i++){
                if(it.second[i-1]+1 == it.second[i]){
                    res += count;
                    res %= mod;
                    count++;
                }
                else{
                    res += count;
                    res %= mod;
                    count = 1;
                }
            }
            res += count;
            res %= mod;
        }
        return res;
    }
};


// Solution 2 without using Hashmap
// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    int mod = 1e9+7;
    int countHomogenous(string s) {
        int res = 1, count = 1;
        for(int i = 1; i < s.size();i++){
            if(s[i-1] == s[i])
                count++;
            else
                count = 1;
            res = (res+count) % mod;
        }
        return res;
    }
};