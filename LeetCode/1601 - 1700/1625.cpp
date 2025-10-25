// 1625. Lexicographically Smallest String After Applying Operations

// Solution 1: Brute Force + Simulation
// Time Complexity: O(100*n)
// Space Complexity: O(n)
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        queue<string> q;
        string res = s;
        q.push(s);
        visited.insert(s);
        int n = s.size();
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            // operation 1
            string next = curr;
            for(int i = 1; i < n;i+=2){
                next[i] = (next[i] - '0' + a) % 10 + '0';
            }
            if(visited.find(next) == visited.end()){
                q.push(next);
                visited.insert(next);
                res = min(res, next);
            }
            // operation 2
            next = curr.substr(n-b) + curr.substr(0, n-b);
            if(visited.find(next) == visited.end()){
                q.push(next);
                visited.insert(next);
                res = min(res, next);
            }
        }
        return res;
    }
};

// Approach 2: Mathematical Observation
// Time Complexity: O(100*n)
// Space Complexity: O(n)
// if b is even
// generate all string possibilties with operation add a on all odd indices (upto 10)
// rotate the string using operation b and get the min string -> O(10*n)
// if b is odd (you can do add a on any type of index)
// so we need to get 
// odd add a * even add a opeartions (10 * 10)
// then rotate the string for each of them using operations b -> O(100*n)
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string res = s;
        int n = s.length();

        if (b % 2 == 0) {
            string current_add_s = s;
            for (int i = 0; i < 10; ++i) {
                if (i > 0) {
                    for (int k = 1; k < n; k += 2) {
                        current_add_s[k] =
                            ((current_add_s[k] - '0' + a) % 10) + '0';
                    }
                }

                string s_to_rotate = current_add_s;
                for (int j = 0; j < n; ++j) {
                    s_to_rotate = s_to_rotate.substr(n - b) +
                                  s_to_rotate.substr(0, n - b);
                    res = min(res, s_to_rotate);
                }
            }
        } else {
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    string candidate_s = s;
                    for (int k = 0; k < n; ++k) {
                        if (k % 2 == 0) {
                            candidate_s[k] = ((s[k] - '0' + i * a) % 10) + '0';
                        } else {
                            candidate_s[k] = ((s[k] - '0' + j * a) % 10) + '0';
                        }
                    }

                    string s_to_rotate = candidate_s;
                    for (int k = 0; k < n; ++k) {
                        s_to_rotate = s_to_rotate.substr(n - b) +
                                      s_to_rotate.substr(0, n - b);
                        res = min(res, s_to_rotate);
                    }
                }
            }
        }

        return res;
    }
};