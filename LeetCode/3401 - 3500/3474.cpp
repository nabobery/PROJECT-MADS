// 3474. Lexicographically Smallest Generated String

// Solution 1: Greedy + Logic (early exit on violation)
// Time Complexity: O(n*m) in worst case (when all characters in str1 are 'T' and we need to fill all characters in res)
// Space Complexity: O(n+m) for the result string and the unknowns vector
class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string res(n+m-1, '?');
        // Fill the result string based on 'T' in str1
        for(int i = 0; i < n;i++){
            if(str1[i] == 'T'){
                for(int j = i; j < i+m;j++){
                    if(res[j] == '?' || res[j] == str2[j-i]){
                        res[j] = str2[j-i];
                    }
                    // Violation: if there's a conflict in characters, return an empty string
                    else return "";
                }
            }
        }
        // Collect indices of unknown characters and fill them with 'a' initially
        vector<int> unknowns;
        for(int i = 0; i < n+m-1;i++){
            if(res[i] == '?'){
                unknowns.push_back(i);
                res[i] = 'a';
            }
        }
        // Check for violations caused by 'F' in str1 and adjust unknown characters if necessary
        for(int i = 0; i < n; i++){
            if(str1[i] == 'F'){
                // if violation (String view more efficient than substr)
                if(string_view(res).substr(i, m) == str2){
                    auto it = upper_bound(unknowns.begin(), unknowns.end(), i+m-1);
                    // If there are no unknown characters that can be changed to 'b', it's a violation
                    if(it == unknowns.begin()) return "";
                    it--;
                    // If the last unknown character is before the start of the substring, it's a violation
                    if(*it < i) return "";
                    else res[*it] = 'b';
                }
            }
        }
        return res;
    }
};