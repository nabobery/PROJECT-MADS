// 955. Delete Columns to Make Sorted II

// Solution 1: Greedy Appproach
// Time Complexity: O(m * n)
// Space Complexity: O(n)
// The idea is to iterate through each column and check if deleting it is necessary to maintain the sorted order of the rows. 
// We keep track of which pairs of rows are already confirmed to be in sorted order using a boolean array. 
//  If we find a column that causes any unsorted pair, we increment the deletion count and skip that column. 
// Otherwise, we update our boolean array for pairs that are now confirmed to be sorted.
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0, n = strs.size(), m = strs[0].size();
        vector<bool> isSortedPairs(n-1, false);
        for(int i = 0; i < m;i++){
            bool deleteColumn = false;
            for(int j = 0; j < n-1;j++){
                if(strs[j][i] > strs[j+1][i] && !isSortedPairs[j]){
                    res++;
                    deleteColumn = true;
                    break;
                }
            }
            if(!deleteColumn){
                for(int j = 0; j < n-1;j++){
                    if(strs[j][i] < strs[j+1][i]) isSortedPairs[j] = true;
                }
            }
        }
        return res;
    }
};