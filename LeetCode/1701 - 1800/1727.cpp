// 1727. Largest Submatrix With Rearrangements

// Solution 1 using sorting and Cumulative Sum
// Time complexity: O(m*n*log(n))
// Space complexity: O(m*n)
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int res = 0, m = matrix.size(), n = matrix[0].size();
        for(int j = 0; j < n;j++){
            for(int i = 1; i < m;i++){
                if(matrix[i][j] == 1) matrix[i][j] = 1 + matrix[i-1][j];
            }
        }
        for(auto& vec : matrix) sort(vec.begin(), vec.end(), greater<int>());
        for(auto vec : matrix){
            for(int i = 0; i < n;i++){
                res = max(res, vec[i]*(i+1));
            }
        }
        return res;
    }
};

// Solution 2 using sorting and Cumulative Sum but without modifying the original matrix
// Time complexity: O(m*n*log(n))
// Space complexity: O(n)
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> prev(n, 0);
        for(int i = 0; i < m;i++){
            vector<int> curr = matrix[i];
            for(int j = 0; j < n;j++){
                if(curr[j] == 1) curr[j] = 1 + prev[j];
            }
            vector<int> temp = curr;
            sort(temp.begin(), temp.end(), greater<int>());
            for(int j = 0; j < n;j++){
                res = max(res, temp[j]*(j+1));
            }
            prev = curr;
        }
        return res;
    }
};

// Solution 3 without sorting
// Time complexity: O(m*n)
// Space complexity: O(n)
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<pair<int,int>> prev;
        for(int i = 0; i < m;i++){
            vector<pair<int,int>> curr;
            vector<bool> vis(n, false);
            for(auto it : prev){
                if(matrix[i][it.second] == 1){
                    curr.push_back({it.first+1, it.second});
                    vis[it.second] = true;
                }
            }
            for(int j = 0; j < n;j++){
                if(matrix[i][j] == 1 && !vis[j]){
                    curr.push_back({1, j});
                }
            }
            for(int j = 0; j < curr.size();j++){
                res = max(res, curr[j].first*(j+1));
            }
            prev = curr;
        }
        return res;
    }
};


