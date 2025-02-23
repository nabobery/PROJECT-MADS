// 1415. The k-th Lexicographical String of All Happy Strings of Length n

// Solution 1: USing Recursion and Backtracking
// Time Complexity: O(3^n)
// Space Complexity: O(n)
class Solution {
    public:
        set<string> st;
        void helper(int pos, int& n, string curr){
            if(pos == n){
                st.insert(curr);
                return;
            }
            char prev = curr.empty() ? '#' : curr.back();
            for(char ch = 'a'; ch <= 'c';ch++){
                if(prev != ch){
                    curr.push_back(ch);
                    helper(pos+1, n, curr);
                    curr.pop_back();
                }
            }
        }
        string getHappyString(int n, int k) {
            string curr;
            helper(0, n, curr);
            if(k > st.size()) return "";
            auto it = st.begin();
            k--;
            while(k--)
                it++;
            return *it;
        }
};

// Solution 2: Using Greedy Recursion and return the kth string when found
// Time Complexity: O(3^n)
// Space Complexity: O(n)
class Solution {
    public:
        string result;
        int count = 0;
    
        void helper(int pos, int n, string& curr, int k) {
            if (pos == n) {
                count++;
                if (count == k) result = curr;
                return;
            }
    
            if (!result.empty()) return; 
    
            for (char ch = 'a'; ch <= 'c'; ch++) {
                if (curr.empty() || curr.back() != ch) {
                    curr.push_back(ch);
                    helper(pos + 1, n, curr, k);
                    curr.pop_back();
                }
            }
        }
    
        string getHappyString(int n, int k) {
            string curr;
            helper(0, n, curr, k);
            return result;
        }
};
    