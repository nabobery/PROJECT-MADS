// 744. Find Smallest Letter Greater Than Target
 
// Solution 1: Simple Linear Scan 
// Time Complexity: O(N)
// Space Complexity: O(26) = O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<bool> visited(26, false);
        vector<char> sortedChars;
        for(auto& ch: letters){
            if(!visited[ch-'a']){
                visited[ch-'a'] = true;
                sortedChars.push_back(ch);
            }
        }
        for(auto& ch: sortedChars) if(ch > target) return ch;
        return sortedChars[0];
    }
};
