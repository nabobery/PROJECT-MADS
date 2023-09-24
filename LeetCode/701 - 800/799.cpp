// 799. Champagne Tower
// O(R^2) time and space solution which is O(1) as R <= 100
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // dp[i][j] = amount of champagne in glass (i,j)
        double arr[102][102] = {0};
        // initialize the first glass
        arr[0][0] = (double) poured;
        // fill the glasses
        for(int i = 0; i <= query_row;i++){
            for(int j = 0; j <= query_glass;j++){
                double q = (arr[i][j] - 1.0)/2.0;
                // if the glass has more than 1 cup of champagne
                // then it will overflow to the next glasses
                if(q > 0){
                    arr[i+1][j] += q;
                    arr[i+1][j+1] += q;
                }
            }
        }
        // return the amount of champagne in the glass
        return min(1.0,arr[query_row][query_glass]);
    }
};




