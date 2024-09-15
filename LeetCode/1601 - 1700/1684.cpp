// 1684. Count the Number of Consistent Strings

// Solution 1: Straightforward Approach using Hash Set
// Time complexity: O(n*m), where n is the length of the input array and m is the length of the longest string
// Space complexity: O(1)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> seen(26, false);
        for(char ch : allowed) seen[ch - 'a'] = true;
        int res = words.size();
        for(string word: words){
            for(char ch : word){
                if(!seen[ch - 'a']){
                    res--;
                    break;
                }
            }
        }
        return res;
    }
};

// Solution 2: Using Bit Manipulation
// Time complexity: O(n*m), where n is the length of the input array and m is the length of the longest string
// Space complexity: O(1)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;
        for(char ch : allowed) mask |= 1 << (ch - 'a');
        int res = words.size();
        for(string word: words){
            for(char ch : word){
                if(!(mask & (1 << (ch - 'a')))){
                    res--;
                    break;
                }
            }
        }
        return res;
    }
};