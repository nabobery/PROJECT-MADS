// 1128. Number of Equivalent Domino Pairs

// Solution 1: Using Sorting 
// Time Complexity: O(n log n) where n is the number of dominoes
// Space Complexity: O(1) for sorting in place
class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            int res = 0, n = dominoes.size();
            for(int i = 0; i < n;i++){
                int mi = min(dominoes[i][0], dominoes[i][1]), mx = max(dominoes[i][0], dominoes[i][1]);
                dominoes[i][0] = mi;
                dominoes[i][1] = mx;
            }
            sort(dominoes.begin(), dominoes.end());
            int curr = 1;
            for(int i = 1; i < n;i++){
                if(dominoes[i] == dominoes[i-1]) curr++;
                else curr = 1;
                res += (curr-1);
            }
            return res;
        }
    };

// Solution 2: Using HashMap
// Time Complexity: O(n) where n is the number of dominoes
// Space Complexity: O(1) for storing the frequency of each domino (as 1 <= dominoes[i][j] <= 9 => 90 possible pairs)
class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            int count[100] = {0};
            int res = 0;
            for (auto& d : dominoes) {
                int a = min(d[0], d[1]);
                int b = max(d[0], d[1]);
                int key = a * 10 + b;
                res += count[key]; 
                count[key]++;
            }
            return res;
        }
};