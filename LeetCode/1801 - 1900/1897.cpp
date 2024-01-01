// 1897. Redistribute Characters to Make All Strings Equal

// Solution 1 Easy and simple by maintaining a frequency array
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        int cnt[26] = {0};
        for(string word : words)
            for(char ch : word) cnt[ch - 'a']++;
        for(auto i : cnt)
            if(i%n) return false;
        return true;
    }
};