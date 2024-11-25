// 773. Sliding Puzzle

// Solution 1: Using BFS
// Time complexity: O(6^6)
// Space complexity: O(6^6)
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string curr_state, final_state = "123450";
        int m = board.size(), n = board[0].size();
        for (const auto& row : board) for (int num : row) curr_state += to_string(num);
        unordered_set<string> vis;
        queue<string> q;
        q.push(curr_state);
        vis.insert(curr_state);
        int moves = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s;i++){
                curr_state = q.front();
                q.pop();
                if(curr_state == final_state) return moves;
                int ind = 0;
                for(;ind < m*n;ind++)
                    if(curr_state[ind] == '0') break;
                // to move the 0 to the left, right, up, down
                // we can move 0 to to the left only if it is not in the first column
                if(ind%n > 0){
                    string next_state = curr_state;
                    swap(next_state[ind], next_state[ind-1]);
                    if(!vis.count(next_state)){
                        q.push(next_state);
                        vis.insert(next_state);
                    } 
                }
                // to move the 0 to the right, it should not be in the last column
                if(ind % n < n - 1){
                    string next_state = curr_state;
                    swap(next_state[ind], next_state[ind+1]);
                    if(!vis.count(next_state)){
                        q.push(next_state);
                        vis.insert(next_state);
                    }
                }
                // to move the 0 up, it should not be in the first row
                if(ind-n >= 0){
                    string next_state = curr_state;
                    swap(next_state[ind], next_state[ind-n]);
                    if(!vis.count(next_state)){
                        q.push(next_state);
                        vis.insert(next_state);
                    }
                }
                // to move the 0 down, it should not be in the last row
                if(ind+n < m*n){
                    string next_state = curr_state;
                    swap(next_state[ind], next_state[ind+n]);
                    if(!vis.count(next_state)){
                        q.push(next_state);
                        vis.insert(next_state);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};

// Cleaner Solution 1
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string curr_state, final_state = "123450";
        int m = board.size(), n = board[0].size();
        
        for (const auto& row : board) {
            for (int num : row) {
                curr_state += to_string(num);
            }
        }
        
        unordered_set<string> vis;
        queue<string> q;
        q.push(curr_state);
        vis.insert(curr_state);
        
        int moves = 0;
        
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                curr_state = q.front();
                q.pop();
                
                if (curr_state == final_state) return moves;
                
                int ind = curr_state.find('0');
                vector<int> directions = {-1, 1, -n, n};
                
                for (int d : directions) {
                    int new_ind = ind + d;
                    if ((d == -1 && ind % n > 0) || 
                        (d == 1 && ind % n < n - 1) || 
                        (d == -n && ind >= n) || 
                        (d == n && ind < m * n - n)) {
                        
                        string next_state = curr_state;
                        swap(next_state[ind], next_state[new_ind]);
                        
                        if (!vis.count(next_state)) {
                            q.push(next_state);
                            vis.insert(next_state);
                        }
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};