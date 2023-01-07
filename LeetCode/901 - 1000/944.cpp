// 944. Delete Columns to Make Sorted

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size(), result = 0;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < strs.size()-1;j++){
                if(strs[j][i] <= strs[j+1][i]) continue;
                else{
                    result++;
                    break;
                }
            }
        }
        return result;
    }
};