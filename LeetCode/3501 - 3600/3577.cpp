// 3577. Count the Number of Computer Unlocking Permutations

// Solution 1: Using Math and Combinatorics
// Time Complexity: O(n)
// Space Complexity: O(1)
// Explanation: The first computer must have the lowest complexity to unlock all others, if not return 0. Otherwise, the number of permutations is (n-1)!.
class Solution {
public:
    const int mod = 1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        bool isValid = true;
        int n = complexity.size();
        long res = 1;
        for(int i = 1; i < n;i++){
            if(complexity[i] <= complexity[0]){
                isValid = false;
                break;
            }
            res = (res*i)% mod;
        }
        if(!isValid) return 0;
        return res;
    }
};