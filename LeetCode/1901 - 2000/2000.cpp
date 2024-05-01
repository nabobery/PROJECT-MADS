// 2000. Reverse Prefix of Word

// Simple Solution 1 
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int r = -1, n = word.size();
        for(int i = 0; i < n;i++){
            if(word[i] == ch){
                r = i;
                break;
            }
        }
        if(r != -1)
            for(int i = 0; i <= r/2;i++) 
                swap(word[i], word[r-i]);
        return word;
    }
};

// Solution 2 using std::reverse
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto it = find(word.begin(), word.end(), ch);
        if(it != word.end())
            reverse(word.begin(), it+1);
        return word;
    }
};