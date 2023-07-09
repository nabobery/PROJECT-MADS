// 118. Pascal's Triangle
// my naive solution
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        int n = (numRows*(numRows + 1))/2;
        int dp [n];
        dp[0] = 1;
        vector<vector<int>> result;
        for(int i = 2; i <= numRows;i++){
            int tmp = (i*(i-1))/2;
            int j = 0;
            while(j < i){
                if(j == 0 || j == i - 1)
                    dp[j + tmp] = 1;
                else{
                    dp[j + tmp] = dp[j + tmp -i] + dp[j+ tmp -i +1];
                }
                j++;
            }
        }
        for(int i = 1; i <= numRows;i++){
            int j = 0;
            int tmp = (i*(i-1))/2;
            vector<int> temp;
            while(j < i){
                temp.push_back(dp[j + tmp]);
                j++;
            }
            result.push_back(temp);
        }

        return result;

    }
};


// another naive solution of mine 0 ms
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        else{
            vector<vector<int>> result(numRows);
            result[0] = {1};
            for(int i = 2; i <= numRows;i++){
                vector<int> temp(i);
                for(int j = -1; j < i-1;j++){
                    int t = (j == -1 ? 0 : result[i-2][j]);
                    t += (j == i-2 ? 0 : result[i-2][j+1]);
                    temp[j+1] = t;
                }
                result[i-1] = temp;
            }
            return result;
        }
    }
};
