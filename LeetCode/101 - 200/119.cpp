// 119. Pascal's Triangle II
// O(rowIndex) space(which is resultant vector) and O(rowIndex^2) time
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result = {1};
        for(int i = 1; i <= rowIndex;i++){
            result.push_back(0);
            for(int j = i; j > 0; j--){
                result[j] += result[j-1];
            }
        }
        return result;
    }
};

