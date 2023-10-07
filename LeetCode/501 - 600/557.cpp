// 557. Reverse Words in a String III

// Solution 1 using Stack
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    string reverseWords(string s) {
        stack<char> stk;
        string result = "";
        for(int i = 0; i < s.size();i++){
            if(s[i] != ' ') stk.push(s[i]);
            else{
                while(!stk.empty()){
                    result += stk.top();
                    stk.pop();
                }
                result += " ";
            }
        }
        while(!stk.empty()){
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};

// Solution 2 using two pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    string reverseWords(string s) {
        int l = 0, r;
        for(int i = 0; i < s.size();i++){
            if(s[i] == ' '){
                r = i-1;
                while(l < r){
                    swap(s[l], s[r]);
                    l++;
                    r--;
                }
                l = i+1;
            }
        }
        r = s.size()-1;
        while(l < r){
            swap(s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }
};