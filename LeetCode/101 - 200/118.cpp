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

