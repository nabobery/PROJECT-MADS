// 2839. Check if Strings Can be Made Equal With Operations I

// Solution 1: Use sets to store the characters in each string, and check if the sets are equal.
// Time complexity: O(4) = O(1),
// Space complexity: O(4) = O(1).
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        unordered_set<char> s11, s12, s21, s22;
        for(int i = 0; i < 4;i+=2){
            s11.insert(s1[i]);
            s21.insert(s2[i]);
        }
        for(int i = 1; i < 4;i+=2){
            s12.insert(s1[i]);
            s22.insert(s2[i]);
        }
        return (s11 == s21) && (s12 == s22);
    }
};

// Solution 2: check if the characters at even indices are in the same set (compare min and max) in both strings, and the characters at odd indices are in the same set (compare min and max) in both strings.
// Time complexity: O(4) = O(1),
// Space complexity: O(1).
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        return 
            min(s1[0], s1[2]) == min(s2[0], s2[2]) &&
            max(s1[0], s1[2]) == max(s2[0], s2[2]) &&
            min(s1[1], s1[3]) == min(s2[1], s2[3]) &&
            max(s1[1], s1[3]) == max(s2[1], s2[3]);
    }
};