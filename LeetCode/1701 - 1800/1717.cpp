// 1717. Maximum Score From Removing Substrings

// Solution 1: Greedy Approach using stack
// Time Complexity: O(n)
// Space Complexity: O(n)
// The idea is to first remove the high priority pair and then remove the low priority pair.
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalScore = 0;
        string highPriorityPair = x > y ? "ab" : "ba";
        string lowPriorityPair = highPriorityPair == "ab" ? "ba" : "ab";
        string stringAfterFirstPass = removeSubstring(s, highPriorityPair);
        int removedPairsCount = (s.size() - stringAfterFirstPass.size()) / 2;
        totalScore += removedPairsCount * max(x, y);
        string stringAfterSecondPass =
            removeSubstring(stringAfterFirstPass, lowPriorityPair);
        removedPairsCount =
            (stringAfterFirstPass.size() - stringAfterSecondPass.size()) /2;
        totalScore += removedPairsCount * min(x, y);

        return totalScore;
    }

private:
    string removeSubstring(const string& input, const string& targetPair) {
        stack<char> charStack;
        for (char currentChar : input) {
            if (currentChar == targetPair[1] && !charStack.empty() &&
                charStack.top() == targetPair[0]) {
                charStack.pop();  
            } else {
                charStack.push(currentChar);
            }
        }
        string remainingChars;
        while (!charStack.empty()) {
            remainingChars += charStack.top();
            charStack.pop();
        }
        reverse(remainingChars.begin(), remainingChars.end());
        return remainingChars;
    }
};

// Solution 2: Greedy Approach without using stack using two pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        if (x > y) {
            // Remove "ab" first (higher points), then "ba"
            res += removeSubstring(s, "ab", x);
            res += removeSubstring(s, "ba", y);
        } else {
            // Remove "ba" first (higher or equal points), then "ab"
            res += removeSubstring(s, "ba", y);
            res += removeSubstring(s, "ab", x);
        }
    }
    int removeSubstring(string& s, string pair, int points){
        int r = 0, w = 0, res = 0;
        for(int r = 0; r < s.size();r++){
            s[w++] = s[r];
            if(w >= 2 && s[w-2] == pair[0] && s[w-1] == pair[1]){
                w -= 2;
                res += points;
            }
        }
        s.erase(s.begin() + w, s.end());
        return res;
    }
};

// Solution 3: Greedy Approach with Counting
// Time Complexity: O(n)
// Space Complexity: O(1)
// The idea is to first remove the high priority pair and then remove the low priority pair in a segmented way.
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0, count_a = 0, count_b = 0;
        if(x < y){
            swap(x, y);
            reverse(s.begin(), s.end());
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a'){
                count_a++;
            } else if(s[i] == 'b'){
                if(count_a > 0){
                    count_a--;
                    res += x;
                } else {
                    count_b++;
                }
            }
            else{
                // If we encounter any other character, we need to remove all the pairs of 'ab' we have encountered so far
                res += min(count_a, count_b) * y;
                count_a = 0;
                count_b = 0;
            }
        }
        res += min(count_a, count_b) * y;
        return res;
    }
};

