// 2515. Shortest Distance to Target String in a Circular Array

// Solution 1: Two Pointers (Straightforward)
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size(), res = -1, steps = 0, l = startIndex, r = startIndex;
        while(steps < n){
            if(words[l] == target || words[r] == target) return steps;
            l = (l-1+n)%n;
            r = (r+1)%n;
            steps++;
        }
        return res;
    }
};