// 58. Length of Last Word

// Solution 1 Naive Approach using isalpha
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = s[0] != ' ';
        for(int i = 1; i < s.size();i++){
            if(isalpha(s[i])){
                if(s[i-1] == ' ') res = 0;
                res++;
            }
        }
        return res;
    }
};

// Solution 2 using istringstream
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        string word;
        while(iss >> word);
        return word.size();
    }
};