// 2840. Check if Strings Can be Made Equal With Operations II

// Solution 1: Using Multiset by keeping track of characters at even and odd indices separately
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        multiset<char> s11, s12, s21, s22;
        int n = s1.size();
        for(int i = 0; i < n;i+=2){
            s11.insert(s1[i]);
            s21.insert(s2[i]);
        }
        for(int i = 1; i < n;i+=2){
            s12.insert(s1[i]);
            s22.insert(s2[i]);
        }
        return (s11 == s21) && (s12 == s22);
    }
};

// Solution 2: Using Frequency Array by keeping track of characters at even and odd indices separately
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int even[26] = {0}, odd[26] = {0};
        int n = s1.size();
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            } else {
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (even[i] != 0 || odd[i] != 0) {
                return false;
            }
        }
        return true;
    }
};