// 2452. Words Within Two Edits of Dictionary


// Solution 1: Brute Force
// Time Complexity: O(q * d * n)
// Space Complexity: O(1) (not counting the output array)
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int q = queries.size(), d = dictionary.size(), n = queries[0].size();
        vector<string> res;
        for(int i = 0; i < q;i++){
            for(int j = 0; j < d;j++){
                int dist = 0;
                for(int k = 0; k < n;k++){
                    if(queries[i][k] != dictionary[j][k]) dist++;
                    if(dist > 2) break;
                }
                if(dist <= 2){
                    res.push_back(queries[i]);
                    break;
                }
            }
        }
        return res;
    }
};