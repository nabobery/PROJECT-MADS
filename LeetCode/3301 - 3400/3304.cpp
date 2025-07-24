// 3304. Find the K-th Character in String Game I

// Solution 1: Simple and Straight Forward Approach
// Time Complexity: O(k)
// Space Complexity: O(k)
class Solution {
public:
    char kthCharacter(int k) {
        int operations = log2(k) + 1;
        string word = "a";
        for(int i = 0; i < operations;i++){
            string temp = word;
            for(int i = 0; i < word.size();i++){
                temp += (((word[i] - 'a' + 1) % 26) + 'a');
            }
            word = temp;
        }
        return word[k-1];
    }
};