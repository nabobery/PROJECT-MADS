// 679. 24 Game

// Solution 1: BruteForce/Recursion + Backtracking
// Time Complexity: O(4! * 4^3 * 5) = O(1)
// Space Complexity: O(1)
class Solution {
public:
    const double eps = 1e-6;
    bool helper(vector<double> cards){
        if(cards.size() == 1)
            return abs(cards[0] - 24.0) < eps;
        int n = cards.size();
        for(int i = 0; i < n;i++){
            for(int j = i+1; j < n;j++){
                vector<double> temp;
                for(int k = 0; k < n;k++){
                    if(k != i && k != j) temp.push_back(cards[k]);
                }
                vector<double> candidates = {
                    cards[i] + cards[j],
                    cards[i] - cards[j],
                    cards[j] - cards[i],
                    cards[i] * cards[j]
                };
                if(cards[j] > eps) candidates.push_back(cards[i]/cards[j]);
                if(cards[i] > eps) candidates.push_back(cards[j]/cards[i]);
                for(auto& candidate : candidates){
                    temp.push_back(candidate);
                    if(helper(temp)) return true;
                    temp.pop_back();
                }
            }
        }
        return false;

    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> arr(cards.begin(), cards.end());
        return helper(arr);
    }
};