// 316. Remove Duplicate Letters
// O(n) time and space solution (as we maintain a resultant string)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        // initialise resultant string
        string result = "";
        // vectors for maintaining visited and frequency of characters in the string
        vector<int> freq(26,0);
        vector<bool> visited(26,false);
        // calculate the frequency
        for(char ch : s){
            freq[ch - 'a']++;
        }
        // traverse the string
        for(char curr: s){
            // decrease the frequency of current characters
            freq[curr - 'a']--;
            // if current character is not visited
            if(!visited[curr -'a']){
                // if last character of the resultant string is greater than current char and that character can be read again (frequency > 0)
                // then remove the last character until the condition is satisfied
                while(!result.empty() && result.back() > curr && freq[result.back()-'a'] > 0){
                    // set visited to false
                    visited[result.back() - 'a'] = false;
                    // remove the last character
                    result.pop_back();
                }
                // add current char to result
                result += curr;
                // set visited to true
                visited[curr - 'a'] = true;
            }
        }
        // return result
        return result;
    }
};

// O(n) time and space solution using stack
class Solution {
public:
    string removeDuplicateLetters(string s) {
        // vector for getting the last seen index of character
        vector<int> last(26,0);
        // vector for storing visited
        vector<bool> visited(26,false);
        stack<char> stk;
        int n = s.size();
        // get the last seen indices of characters
        for(int i = 0; i < n;i++){
            last[s[i]-'a'] = i;
        }
        // traverse the string
        for(int i = 0; i < n;i++){
            int curr = s[i]  - 'a';
            // if already visited then continue
            if(visited[curr]) continue;
            // if character at the top of the stack is greater than current char and that character can be read again (i < lastindex)
            // then remove the last character until the condition is satisfied
            while(!stk.empty() && stk.top() > s[i] && i < last[stk.top() - 'a']){
                // set visited to false
                visited[stk.top() - 'a'] = false;
                // remove the top character
                stk.pop();
            }
            // push the current char into stack
            stk.push(s[i]);
            // mark visited as true
            visited[curr] = true;
        }
        // resultant string
        string result = "";
        // get the reverse string from the stack
        while(!stk.empty()){
            result += stk.top();
            stk.pop();
        }
        // reverse it to get the final result
        reverse(result.begin(),result.end());
        return result;
    }
};
