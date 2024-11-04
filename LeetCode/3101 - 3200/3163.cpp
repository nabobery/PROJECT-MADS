// 3163. String Compression III

// Solution 1: Simple and Straightforward
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string compressedString(string word) {
        string res;
        word += '#';
        int n = word.size(), curr = 1;
        char prev = word[0];
        for(int i = 1; i < n;i++){
            if(word[i] == prev) curr++;
            else{
                while(curr > 0){
                    res += (min(curr, 9) + '0');
                    res += prev;
                    curr -= 9;
                }
                curr = 1;
            }
            prev = word[i];
        }
        return res;

    }
};