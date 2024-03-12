// 948. Bag of Tokens

// Solution 1 - Greedy using Sorting and Two Pointers
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size(), res = 0, l = 0, r= n-1, curr = 0;
        while(l <= r){
            if(power < tokens[l]){
                if(power+tokens[r] > tokens[l] && curr > 0){
                    power += tokens[r];
                    r--;
                    curr--;
                }
                else break;
            }
            else if(power >= tokens[l]){
                power -= tokens[l];
                l++;
                curr++;
                res = max(curr, res);
            }
        } 
        return res;
    }
};