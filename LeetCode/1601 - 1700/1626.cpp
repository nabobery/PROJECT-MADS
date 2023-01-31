// 1626. Best Team With No Conflicts

class Solution {
public:
    int helper(vector<pair<int,int>>& agesScores){
        int n = agesScores.size(), result = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = agesScores[i].second;
            result = max(result, dp[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (agesScores[i].second >= agesScores[j].second) {
                    dp[i] = max(dp[i], agesScores[i].second + dp[j]);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>> agesScores(n, {0,0});
        for(int i = 0; i < n;i++){
            agesScores[i].first = ages[i];
            agesScores[i].second = scores[i];
        }
        sort(agesScores.begin(), agesScores.end());
        return helper(agesScores);
    }
};
