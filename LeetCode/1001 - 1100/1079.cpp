// 1079. Letter Tile Possibilities

// Solution 1 By Finding the number of permutations of each length (subset) of the given string
// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
class Solution {
    public:
        int res;
        set<vector<int>> subset;
        int factorial(int n){
            if(n == 0 || n == 1)
                return 1;
            else
                return (n *factorial(n-1));
        }
    
        void helper(int ind, string& curr, string& tiles){
            if(ind == tiles.size()){
                vector<int> freq(26, 0);
                for(int i = 0; i < curr.size();i++)
                    freq[curr[i] - 'A']++;
                if(!subset.count(freq)){
                    subset.insert(freq);
                    int result = 1;
                    for(int i = 0; i < 26;i++)
                        result *= factorial(freq[i]);
                    result = factorial(curr.size())/result;
                    res += result;
                }
                return;
            }
            helper(ind+1, curr, tiles);
            curr.push_back(tiles[ind]);
            helper(ind+1, curr, tiles);
            curr.pop_back();
        }
        int numTilePossibilities(string tiles) {
            string curr;
            res = 0;
            helper(0, curr, tiles);
            return res-1;
        }
};