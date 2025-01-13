// 1400. Construct K Palindrome Strings

// Solution 1 using Greedy approach
// Time complexity: O(n)
// Space complexity: O(1)
// Palindrome can be formed if the number of odd frequency characters is less than or equal to k
class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> cnt(26, 0);
        for(char& ch : s) cnt[ch - 'a']++;
        int odd = 0, even_pairs = 0;
        for(int i : cnt){
            odd += (i%2);
            even_pairs += (i/2);
        }
        if(odd > k) return false;
        return (even_pairs*2 + odd >= k);
    }
};

// Cleaner version of the above solution
class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> cnt(26, 0);
        for(char& ch : s) cnt[ch - 'a']++;
        int odd = 0;
        for(int i : cnt) odd += (i%2);
        return odd > k ? false : s.size() >= k;
    }
};