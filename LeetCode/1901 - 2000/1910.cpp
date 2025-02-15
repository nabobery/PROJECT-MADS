// 1910. Remove All Occurrences of a Substring

// Solution 1: Straight-forward Solution by deleting part until no more substring found
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        size_t pos = s.find(part);
        while (pos != string::npos)
        {
            s.replace(pos, part.length(), "");
            pos = s.find(part);
        }
        return s;
    }
};
