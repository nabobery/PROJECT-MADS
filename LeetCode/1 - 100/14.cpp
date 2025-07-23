// 14. Longest Common Prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];
        int n = strs.size();
        for(int i = 1; i < n;i++){
            for(int j = 0; j < min(strs[i].size(), common.size());j++){
                if(common[j] != strs[i][j]){
                    common = common.substr(0, j);
                    break;
                }
            }
            if(common.size() > strs[i].size()) common = common.substr(0, strs[i].size());
            if(common.empty()) break;
        }
        return common;
    }
};
