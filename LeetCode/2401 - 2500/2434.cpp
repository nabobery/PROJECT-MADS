// 2434. Using a Robot to Print the Lexicographically Smallest String

// Solution 1: Greedy Approach using Stack and Character Frequency Count
// Time Complexity: O(n), where n is the length of the input string.    
// Space Complexity: O(n)
// The solution uses a greedy approach to construct the lexicographically smallest string by maintaining a stack and a frequency count of characters. It iterates through the input string, updating the stack and result string based on the smallest character that can be printed next.
class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        // final result paper string
        string res;
        // stack to maintain the string t
        stack<char> t;
        // frequency count of characters in the string
        vector<int> cnt(26, 0);
        for(char& c: s) cnt[c - 'a']++;
        int p = 0;
        // choose the smallest character that can be printed next
        while(p < 26){
            if(cnt[p] != 0) break;
            p++;
        }
        // iterate through the string s
        for(int i = 0; i < n;i++){
            char ch = s[i];
            int idx = ch - 'a';
            // decrease the count of the current character
            cnt[idx]--;
            // if the current character is the smallest one that can be printed
            if(idx == p){
                // print the character and pop from stack if possible
                res += ch;
                // if the count of the current character is zero, update the smallest character
                if(cnt[idx] == 0){
                    int np = p;
                    while(np < 26){
                        if(cnt[np] != 0) break;
                        np++;    
                    }
                    // pop from stack until the top character is greater than the new smallest character
                    while(!t.empty() && (t.top() - 'a') <= np){
                        res += t.top();
                        t.pop();
                    }
                    p = np;
                }
            }
            else t.push(ch);
        }
        // pop all remaining characters from the stack
        // and append them to the result
        while(!t.empty()){
            res += t.top();
            t.pop();
        }
        return res;
    }
};