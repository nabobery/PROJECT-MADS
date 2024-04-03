// 205. Isomorphic Strings

// Solution 1 Using 2 Hash Maps
// Time complexity: O(n)
// Space complexity: O(n)
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int n = s.size();
        unordered_map<char, vector<int>> cnt1, cnt2;
        for (int i = 0; i < n; i++)
        {
            cnt1[s[i]].push_back(i);
            cnt2[t[i]].push_back(i);
        }
        for (auto it : cnt1)
        {
            bool b = false;
            for (auto itr : cnt2)
            {
                if (it.second == itr.second)
                {
                    b = true;
                    break;
                }
            }
            if (!b)
                return false;
        }
        return true;
    }
};

// Solution 2 Using 1 Hash Map
// Time complexity: O(n)
// Space complexity: O(n)
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int n = s.size();
        unordered_map<char, char> mp;
        unordered_set<char> st;
        for (int i = 0; i < n; i++)
        {
            if (!mp.count(s[i]))
            {
                if (st.count(t[i]))
                    return false;
                mp[s[i]] = t[i];
                st.insert(t[i]);
            }
            else
            {
                if (mp[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};