// 1371. Find the Longest Substring Containing Vowels in Even Counts

// Solution 1 using Bit Manipulation and Unordered Map
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    unordered_map<char, int> vowel = {
        {'a', 0},
        {'e', 1},
        {'i', 2},
        {'o', 3},
        {'u', 4}};
    int findTheLongestSubstring(string s)
    {
        int n = s.size(), res = 0, mask = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++)
        {
            if (vowel.count(s[i]))
                mask ^= (1 << vowel[s[i]]);
            if (mp.count(mask))
                res = max(res, i - mp[mask]);
            else
                mp[mask] = i;
        }
        return res;
    }
};

// Solution 2 using Bit Manipulation and Vector
class Solution
{
public:
    unordered_map<char, int> vowel = {
        {'a', 0},
        {'e', 1},
        {'i', 2},
        {'o', 3},
        {'u', 4}};
    int findTheLongestSubstring(string s)
    {
        int n = s.size(), res = 0, mask = 0;
        vector<int> mp(33, -2);
        mp[0] = -1;
        for (int i = 0; i < n; i++)
        {
            if (vowel.count(s[i]))
                mask ^= (1 << vowel[s[i]]);
            if (mp[mask] != -2)
                res = max(res, i - mp[mask]);
            else
                mp[mask] = i;
        }
        return res;
    }
};

// More optimized solution 2 using array and memset and by storing masks of vowel in array
class Solution
{
public:
    unordered_map<char, int> vowel = {
        {'a', 1},
        {'e', 2},
        {'i', 4},
        {'o', 8},
        {'u', 16}};
    int mp[33];
    int findTheLongestSubstring(string s)
    {
        int n = s.size(), res = 0, mask = 0;
        memset(mp, -1, sizeof(mp));
        mp[0] = -1;
        for (int i = 0; i < n; i++)
        {
            if (vowel.count(s[i]))
                mask ^= vowel[s[i]];
            if (mp[mask] == -1 && mask != 0)
                mp[mask] = i;
            else
                res = max(res, i - mp[mask]);
        }
        return res;
    }
};