// 2273. Find Resultant Array After Removing Anagrams

// Solution 1: StraightForward and Simple Approach
// Time Complexity: O(n * mlogm) where n is the number of strings and m is the maximum length of a string
// Space Complexity: O(1)
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        int n = words.size();
        res.push_back(words[0]);
        string prev = words[0];
        sort(prev.begin(), prev.end());
        for(int i = 1; i < n;i++){
            string curr = words[i];
            sort(curr.begin(), curr.end());
            if(curr == prev) continue;
            prev = curr;
            res.push_back(words[i]);
        }
        return res;
    }
};

// Cleaner and concise version of the above code
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        string prev = "";
        for (const string& word : words) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            if (sortedWord != prev) {
                res.push_back(word);
                prev = sortedWord;
            }
        }
        return res;
    }
};