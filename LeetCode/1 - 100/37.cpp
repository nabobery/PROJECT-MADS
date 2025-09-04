// 37. Sudoku Solver

// Solution 1: Using Backtracking
// Time Complexity: O((9^m)) where m is the number of empty cells
// Space Complexity: O(1) for the auxiliary space
class Solution {
public:
    bool rows[9][10] = {false};
    bool cols[9][10] = {false};
    bool blocks[9][10] = {false};
    bool helper(int r, int c, vector<vector<char>>& board){
        if(r == 9) return true;
        if(c == 9) return helper(r+1,0, board);
        if(board[r][c] != '.') return helper(r, c+1, board);
        int b = (r/3)*3 + (c/3);
        for(int d = 1; d <= 9;d++){
            if(!rows[r][d] && !cols[c][d] && !blocks[b][d]){
                board[r][c] = d + '0';
                rows[r][d] = cols[c][d] = blocks[b][d] = true;
                if(helper(r, c+1, board)) return true;
                rows[r][d] = cols[c][d] = blocks[b][d] = false;
                board[r][c] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9;i++){
            for(int j = 0; j < 9;j++){
                if(board[i][j] != '.'){
                    int d = board[i][j] - '0';
                    int b = (i/3)*3 + (j/3);
                    rows[i][d] = cols[j][d] = blocks[b][d] = true;
                }
            }
        }
        helper(0, 0, board);
    }
};

// Solution 2: BitMask-optimized backtracking
// Time Complexity: O((9^m)) where m is the number of empty cells
// Space Complexity: O(1) for the auxiliary space
class Solution {
public:
    bool solve(vector<vector<char>>& board, vector<int>& rows, vector<int>& cols, vector<int>& blocks, vector<pair<int, int>>& emptyCells, int index) {
        if(index == emptyCells.size()) return true;
        int r = emptyCells[index].first;
        int c = emptyCells[index].second;
        int b = (r/3)*3 + (c/3);
        for(int d = 0; d < 9; d++) {
            if(!(rows[r] & (1 << d)) && !(cols[c] & (1 << d)) && !(blocks[b] & (1 << d))) {
                board[r][c] = d + '1';
                rows[r] |= (1 << d);
                cols[c] |= (1 << d);
                blocks[b] |= (1 << d);
                if(solve(board, rows, cols, blocks, emptyCells, index + 1)) return true;
                board[r][c] = '.';
                rows[r] &= ~(1 << d);
                cols[c] &= ~(1 << d);
                blocks[b] &= ~(1 << d);
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> rows(9, 0), cols(9, 0), blocks(9, 0);
        vector<pair<int, int>> emptyCells;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    rows[i] |= (1 << num);
                    cols[j] |= (1 << num);
                    blocks[(i/3)*3 + (j/3)] |= (1 << num);
                } else {
                    emptyCells.push_back({i, j});
                }
            }
        }
        solve(board, rows, cols, blocks, emptyCells, 0);
    }
};