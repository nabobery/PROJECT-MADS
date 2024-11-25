// 1861. Rotating the Box

// Solution 1: Using Rotation and Simulation using 2 pointers
// Time complexity: O(n*m)
// Space complexity: O(n*m)
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m, '.'));
        // rotate the box by 90 degrees
        for(int i = 0; i < n;i++)
            for(int j = 0; j < m;j++) res[i][m-j-1] = box[j][i];
        // traverse each column
        for(int i = 0; i < m;i++){
            // initialize the pointer to end row
            int k = n-1;
            // traverse each row
            for(int j = n-1; j >= 0;j--){
                // if the cell is a stone, move it to the end
                if(res[j][i] == '#'){
                    res[j][i] = '.';
                    res[k--][i] = '#';
                }
                // if the cell is an obstacle, update the pointer
                else if(res[j][i] == '*') k = j-1;
            }
        }
        return res;
    }
};