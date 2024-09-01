// 1395. Count Number of Teams

// Solution 1: Brute force
// Time complexity: O(N^3)
// Space complexity: O(1)
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int res = 0;
        for(int i = 0; i < n-2;i++){
            for(int j = i+1; j < n-1;j++){
                for(int k = j+1; k < n;k++){
                    if((rating[i] > rating[j] && rating[j] > rating[k]) || (rating[i] < rating[j] && rating[j] < rating[k])) res++;
                }
            }
        }
        return res;
    }
};

// Solution 2: Using 2D DP
// Time complexity: O(N^2)
// Space complexity: O(N^2)
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        // dp1 to store the number of elements such that rating[i] > rating[j] > rating[k]
        // dp2 to store the number of elements such that rating[i] < rating[j] < rating[k]
        vector<vector<int>> dp1(n, vector<int>(3)), dp2(n, vector<int>(3));
        for(int i = 0; i < n;i++){
            // base case
            dp1[i][0] = dp2[i][0] = 1;
            // dp1[i][1] stores the number of elements such that rating[j] < rating[i]
            // dp2[i][1] stores the number of elements such that rating[j] > rating[i]
            for(int j = 0; j < i;j++){
                if(rating[j] < rating[i])
                    dp1[i][1]++;
                else if(rating[j] > rating[i])
                    dp2[i][1]++;
            }
            // dp1[i][2] stores the number of elements such that rating[j] < rating[i] and rating[j] < rating[k]
            // dp2[i][2] stores the number of elements such that rating[j] > rating[i] and rating[j] > rating[k]
            for(int j = 0; j < i;j++){
                if(rating[j] < rating[i])
                    dp1[i][2] += dp1[j][1];
                else if(rating[j] > rating[i])
                    dp2[i][2] += dp2[j][1];
            }
        }
        // res stores the total number of teams
        int res = 0;
        for(int i = 0; i < n;i++)
            res += dp1[i][2] + dp2[i][2];
        return res;
    }
};

// Solution 3: Using Optimized 1D DP
// Time complexity: O(N^2)
// Space complexity: O(N)
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> dp1(n), dp2(n);
        int res = 0;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < i;j++){
                if(rating[j] < rating[i]){
                    dp1[i]++;
                    res += dp1[j];
                }
                else if(rating[j] > rating[i]){
                    dp2[i]++;
                    res += dp2[j];
                }
            }
        }
        return res;
    }
};